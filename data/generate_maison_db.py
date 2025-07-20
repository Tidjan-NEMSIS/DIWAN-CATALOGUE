import os
import sqlite3
import shutil
import random

# Dossiers source et destination
SRC_IMG_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), 'dataset', 'Houses Dataset', 'Houses Dataset'))
DST_IMG_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '../images'))
DB_PATH = os.path.abspath(os.path.join(os.path.dirname(__file__), 'maison.db'))

def generate_realistic_description(chambres, toilettes, standing):
    """Génère une description plus réaliste et détaillée pour une maison."""
    base_phrases = [
        f"Cette charmante maison de {standing} offre un cadre de vie exceptionnel.",
        f"Spacieuse et lumineuse, cette propriété de {standing} est idéale pour une famille.",
        f"Découvrez cette superbe maison au standing {standing}, un véritable havre de paix.",
        f"Idéalement située, cette maison de {standing} combine confort moderne et élégance."
    ]

    details = [
        f"Elle se compose de {chambres} chambres spacieuses, parfaites pour accueillir toute la famille.",
        f"Avec ses {chambres} chambres, cette maison offre de beaux volumes et de nombreuses possibilités d'aménagement.",
        f"Vous apprécierez les {chambres} chambres bien agencées, offrant confort et intimité."
    ]

    amenities = [
        f"La maison dispose de {toilettes} salles de bains modernes et fonctionnelles.",
        f"Les {toilettes} salles de bains ont été rénovées avec des matériaux de qualité.",
        f"Profitez de {toilettes} points d'eau, incluant une salle de bain principale et une salle d'eau."
    ]

    conclusion = [
        "Le jardin paysager et la terrasse ensoleillée sont parfaits pour des moments de détente en extérieur.",
        "La cuisine ouverte, entièrement équipée, est un véritable atout pour les amateurs de gastronomie.",
        "Un grand salon avec cheminée ajoute une touche chaleureuse et conviviale à l'ensemble.",
        "Ne manquez pas cette opportunité unique de vivre dans un cadre privilégié."
    ]

    description = f"{random.choice(base_phrases)} {random.choice(details)} {random.choice(amenities)} {random.choice(conclusion)}"
    return description

# Valeurs par défaut
DEFAULT_TYPE = 'Maison'
DEFAULT_STANDING = 'Standard'
DEFAULT_CHAMBRES = 4
DEFAULT_TOILETTES = 2
DEFAULT_DESCRIPTION = 'Maison générée automatiquement.'

# Création du dossier images si besoin
os.makedirs(DST_IMG_DIR, exist_ok=True)

# Connexion à la base SQLite
conn = sqlite3.connect(DB_PATH)
c = conn.cursor()
c.execute('''
CREATE TABLE IF NOT EXISTS maison (
    id TEXT PRIMARY KEY,
    type TEXT,
    standing TEXT,
    chambres INTEGER,
    toilettes INTEGER,
    description TEXT,
    photo1 TEXT,
    photo2 TEXT,
    photo3 TEXT,
    photo4 TEXT
)
''')

# Récupérer tous les ids uniques à partir des fichiers d'images
photos = os.listdir(SRC_IMG_DIR)
ids = set()
for filename in photos:
    if filename.endswith('.jpg'):
        id_part = filename.split('_')[0]
        ids.add(id_part)

for id_ in sorted(ids, key=lambda x: int(x)):
    # Génération de données aléatoires pour la maison
    chambres = random.randint(2, 6)
    toilettes = random.randint(1, chambres - 1 if chambres > 1 else 1)
    standings = ['Standard', 'Luxe', 'Moderne', 'Classique', 'Rustique']
    standing = random.choice(standings)
    description = generate_realistic_description(chambres, toilettes, standing)

    # Générer les chemins des 4 photos
    files = {
        'frontal': f'{id_}_frontal.jpg',
        'bedroom': f'{id_}_bedroom.jpg',
        'kitchen': f'{id_}_kitchen.jpg',
        'bathroom': f'{id_}_bathroom.jpg',
    }
    rel_paths = {}
    for key, fname in files.items():
        src = os.path.join(SRC_IMG_DIR, fname)
        dst = os.path.join(DST_IMG_DIR, fname)
        if os.path.exists(src):
            shutil.copy2(src, dst)
            rel_paths[key] = dst
        else:
            rel_paths[key] = ''
            
    # Insertion dans la base
    c.execute('''
        INSERT OR REPLACE INTO maison (id, type, standing, chambres, toilettes, description, photo1, photo2, photo3, photo4)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
    ''', (
        id_,
        DEFAULT_TYPE,
        standing,
        chambres,
        toilettes,
        description,
        rel_paths['frontal'],
        rel_paths['bedroom'],
        rel_paths['kitchen'],
        rel_paths['bathroom'],
    ))
    print(f'Maison {id_} ajoutée.')

conn.commit()
conn.close()
print('Base maison.db générée avec succès !') 