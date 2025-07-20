-- Suppression de la table si elle existe
DROP TABLE IF EXISTS maison;

-- Création de la table
CREATE TABLE maison (
    id TEXT PRIMARY KEY,
    type TEXT NOT NULL,
    standing TEXT NOT NULL,
    chambres INTEGER NOT NULL,
    toilettes INTEGER NOT NULL,
    description TEXT,
    photo1 TEXT,
    photo2 TEXT,
    photo3 TEXT,
    photo4 TEXT
);

-- Insertion des données de test
-- Types de biens
WITH types AS (
    SELECT 'Appartement' as type UNION ALL
    SELECT 'Maison' UNION ALL
    SELECT 'Studio' UNION ALL
    SELECT 'Loft' UNION ALL
    SELECT 'Villa'
),
-- Niveaux de standing
standings AS (
    SELECT 'Économique' as standing UNION ALL
    SELECT 'Standard' UNION ALL
    SELECT 'Confort' UNION ALL
    SELECT 'Premium' UNION ALL
    SELECT 'Luxe'
),
-- Descriptions
descriptions AS (
    SELECT 'Bien situé, proche des commodités' as desc UNION ALL
    SELECT 'Vue imprenable, calme et lumineux' UNION ALL
    SELECT 'Rénové récemment, moderne et fonctionnel' UNION ALL
    SELECT 'Charme et caractère, plein de cachet' UNION ALL
    SELECT 'Idéal pour famille, grand espace de vie'
)
-- Génération des 500 entrées
INSERT INTO maison (id, type, standing, chambres, toilettes, description)
SELECT 
    'MAISON' || printf('%03d', rowid) as id,
    (SELECT type FROM types ORDER BY RANDOM() LIMIT 1) as type,
    (SELECT standing FROM standings ORDER BY RANDOM() LIMIT 1) as standing,
    abs(random() % 5) + 1 as chambres,  -- 1 à 5 chambres
    abs(random() % 3) + 1 as toilettes,  -- 1 à 3 toilettes
    (SELECT desc FROM descriptions ORDER BY RANDOM() LIMIT 1) as description
FROM (
    SELECT rowid
    FROM (
        WITH RECURSIVE
        cnt(x) AS (
            SELECT 1
            UNION ALL
            SELECT x+1 FROM cnt
            LIMIT 500
        )
        SELECT x FROM cnt
    )
);

-- Mise à jour des chemins de photos (simulation)
UPDATE maison
SET 
    photo1 = CASE WHEN random() % 2 = 0 THEN 'images/interieur1.jpg' ELSE NULL END,
    photo2 = CASE WHEN random() % 2 = 0 THEN 'images/interieur2.jpg' ELSE NULL END,
    photo3 = CASE WHEN random() % 2 = 0 THEN 'images/exterieur1.jpg' ELSE NULL END,
    photo4 = CASE WHEN random() % 2 = 0 THEN 'images/exterieur2.jpg' ELSE NULL END;

-- Création d'index pour optimiser les recherches
CREATE INDEX idx_maison_type ON maison(type);
CREATE INDEX idx_maison_standing ON maison(standing);
CREATE INDEX idx_maison_chambres ON maison(chambres);

-- Vérification du nombre d'entrées
SELECT COUNT(*) as nombre_maisons FROM maison;

-- Statistiques sur les types de biens
SELECT type, COUNT(*) as nombre
FROM maison
GROUP BY type
ORDER BY nombre DESC;

-- Statistiques sur les standings
SELECT standing, COUNT(*) as nombre
FROM maison
GROUP BY standing
ORDER BY nombre DESC;

-- Statistiques sur les chambres
SELECT chambres, COUNT(*) as nombre
FROM maison
GROUP BY chambres
ORDER BY chambres; 