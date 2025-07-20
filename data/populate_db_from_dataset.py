import sqlite3
import os
from pathlib import Path
import random

# --- Configuration ---
# Chemin vers le dossier contenant ce script
SCRIPT_DIR = Path(__file__).parent.resolve()
# Chemin vers la base de données à créer
DB_PATH = SCRIPT_DIR / "dataset" / "maison.db"
# Chemin vers le dossier contenant les images des maisons
IMAGES_DIR = SCRIPT_DIR / "dataset" / "houses Dataset" / "Houses Dataset"

# --- Fonctions ---

def create_database_schema(cursor):
    """Crée la table 'maison' en supprimant l'ancienne si elle existe."""
    cursor.execute("DROP TABLE IF EXISTS maison")
    cursor.execute("""
    CREATE TABLE maison (
        id TEXT PRIMARY KEY,
        type TEXT NOT NULL,
        standing TEXT NOT NULL,
        chambres INTEGER NOT NULL,
        toilettes INTEGER NOT NULL,
        description TEXT,
        photo1 TEXT, -- Frontal
        photo2 TEXT, -- Bedroom
        photo3 TEXT, -- Bathroom
        photo4 TEXT  -- Kitchen
    )
    """)
    print("Schéma de la base de données créé.")

def find_and_group_images(images_path):
    """Trouve toutes les images et les regroupe par ID de maison."""
    houses = {}
    if not images_path.exists():
        print(f"ERREUR: Le dossier d'images n'existe pas: {images_path}")
        return {}

    for filename in os.listdir(images_path):
        if filename.lower().endswith('.jpg'):
            try:
                parts = filename.split('_')
                house_id = parts[0]
                room_type = parts[1].split('.')[0]

                if house_id not in houses:
                    houses[house_id] = {}
                
                # Stocker le chemin absolu de l'image
                houses[house_id][room_type] = str(images_path / filename)
            except IndexError:
                print(f"Avertissement: Nom de fichier ignoré (format inattendu): {filename}")
    
    print(f"{len(houses)} maisons identifiées à partir des images.")
    return houses

def populate_database(cursor, houses):
    """Insère les données des maisons dans la base de données."""
    maison_data = []
    house_types = ["Appartement", "Maison de ville", "Villa", "Studio"]
    standings = ["Luxe", "Moyen", "Standard"]

    for house_id, images in houses.items():
        # S'assurer que les 4 photos clés sont présentes
        if all(k in images for k in ['frontal', 'bedroom', 'bathroom', 'kitchen']):
            maison_id_str = f"MAISON{house_id.zfill(3)}"
            
            # Générer des données aléatoires plausibles
            data = (
                maison_id_str,
                random.choice(house_types),
                random.choice(standings),
                random.randint(1, 6),  # chambres
                random.randint(1, 4),  # toilettes
                f"Une belle propriété de type {random.choice(house_types).lower()} avec une vue imprenable.",
                images.get('frontal'),
                images.get('bedroom'),
                images.get('bathroom'),
                images.get('kitchen')
            )
            maison_data.append(data)
        else:
            print(f"Avertissement: Maison {house_id} ignorée (photos manquantes).")

    cursor.executemany("""
    INSERT INTO maison (id, type, standing, chambres, toilettes, description, photo1, photo2, photo3, photo4)
    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    """, maison_data)
    print(f"{len(maison_data)} maisons insérées dans la base de données.")

# --- Exécution principale ---

def main():
    """Fonction principale pour exécuter le script."""
    print("Démarrage du script de peuplement de la base de données...")
    
    # S'assurer que le dossier parent de la DB existe
    DB_PATH.parent.mkdir(exist_ok=True)

    try:
        # Connexion à la base de données
        conn = sqlite3.connect(DB_PATH)
        cursor = conn.cursor()

        # 1. Créer le schéma
        create_database_schema(cursor)

        # 2. Trouver et grouper les images
        houses = find_and_group_images(IMAGES_DIR)

        # 3. Peupler la base de données
        if houses:
            populate_database(cursor, houses)

        # Sauvegarder les changements et fermer la connexion
        conn.commit()
        conn.close()
        print(f"\nOpération terminée avec succès. Base de données '{DB_PATH.name}' prête.")

    except sqlite3.Error as e:
        print(f"Une erreur SQLite est survenue: {e}")
    except Exception as e:
        print(f"Une erreur inattendue est survenue: {e}")

if __name__ == "__main__":
    main()
