import sqlite3
from pathlib import Path

DB_PATH = Path(__file__).parent / "dataset/maison.db"
PHOTOS_DIR = Path(__file__).parent / "dataset/photos"

conn = sqlite3.connect(DB_PATH)
c = conn.cursor()

# Vider et recréer la table
c.execute("DROP TABLE IF EXISTS maison")
c.execute("""CREATE TABLE maison (
    id TEXT PRIMARY KEY,
    type TEXT, standing TEXT,
    chambres INTEGER, toilettes INTEGER,
    description TEXT,
    photo1 TEXT, photo2 TEXT, photo3 TEXT, photo4 TEXT)""")

# Insérer 20 maisons de test
for i in range(1, 21):
    photos = [f"maison_{i:03}_photo_{j}.jpg" for j in range(1,5)]
    c.execute("INSERT INTO maison VALUES (?,?,?,?,?,?,?,?,?,?)", (
        f"MAISON{i:03}", "Appartement", "Moyen", 3, 2,
        "Belle maison spacieuse",
        *(str(PHOTOS_DIR/p) for p in photos)
    ))

conn.commit()
conn.close()

print(f"Base de données peuplée avec succès à {DB_PATH}")
