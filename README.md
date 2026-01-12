#  Mini Cash Power — Simulation en C (Console)

##  Description

Ce projet est une **simulation d’un système de compteur électrique prépayé (Cash Power)**, développée en **langage C**, en mode **console**.

L’objectif est **pédagogique** : comprendre comment fonctionnent les systèmes réels de comptage prépayé utilisés par les sociétés d’électricité, en abordant :

* la **cryptographie de base**
* la **gestion de tokens**
* la **sécurité (anti-réutilisation)**
* la **logique embarquée**
* la **gestion de l’énergie prépayée**

Ce projet s’inspire du fonctionnement réel des compteurs **STS (Standard Transfer Specification)**, mais avec une implémentation **simplifiée et compréhensible**.

---

##  Objectifs pédagogiques

* Comprendre le principe des **tokens prépayés**
* Implémenter un **chiffrement simple** (clé secrète)
* Simuler un **compteur électrique embarqué**
* Appliquer une **architecture modulaire en C**
* Approcher les contraintes des **systèmes embarqués**

---

##  Fonctionnalités

*  Génération de token côté serveur
*  Chiffrement et déchiffrement du token
*  Recharge du compteur via token
*  Protection contre la réutilisation des tokens
*  Gestion du crédit en kWh
*  Simulation de la consommation électrique
*  Interface en ligne de commande

---

##  Structure du projet

```
cashpower_c/
│
├── crypto.h        # Chiffrement / déchiffrement
├── crypto.c
├── compteur.h      # Logique du compteur
├── compteur.c
├── serveur.h       # Génération des tokens
├── serveur.c
├── main.c          # Interface console
└── README.md
```

---

##  Principe de fonctionnement

1. L’utilisateur achète une quantité d’électricité (en kWh).
2. Le serveur génère un **token chiffré** contenant :

   * l’identifiant du compteur
   * la quantité d’énergie achetée
3. L’utilisateur saisit le token dans le compteur.
4. Le compteur :

   * déchiffre le token
   * vérifie sa validité
   * crédite l’énergie
5. Chaque consommation décrémente le crédit.
6. Quand le crédit est épuisé, l’électricité est coupée.

---

##  Principe du chiffrement (simplifié)

Le chiffrement repose sur :

* une **clé secrète**
* une **addition modulaire chiffre par chiffre**
* une opération inverse pour le déchiffrement

>  Ce mécanisme est volontairement simplifié à des fins pédagogiques.
> Les systèmes réels utilisent des algorithmes cryptographiques normalisés (DES/AES).

---

##  Compilation et exécution

### Prérequis

* GCC (Linux / macOS / MinGW sous Windows)

### Compilation

```bash
gcc main.c crypto.c compteur.c serveur.c -o cashpower
```

### Exécution

```bash
./cashpower
```

---

##  Utilisation

Menu principal :

```
1. Acheter électricité
2. Entrer token
3. Consommer
4. État compteur
0. Quitter
```

---

##  Technologies utilisées

* Langage : **C**
* Paradigme : **procédural / modulaire**
* Environnement : **console**
* Style : **embarqué (sans allocation dynamique)**

---

##  Améliorations possibles

* Ajout d’un **compteur de transaction (nonce)**
* Ajout d’un **CRC / checksum**
* Sauvegarde de l’état dans un fichier
* Simulation de coupure automatique
* Portage vers **Arduino / STM32**
* Implémentation d’un chiffrement plus robuste

---

##  Avertissement

Ce projet est **strictement éducatif**.
Il ne doit **pas** être utilisé tel quel dans un système réel de comptage électrique.

---

##  Auteur

Projet réalisé par **jeys47**
Dans un objectif d’apprentissage des systèmes embarqués, de la sécurité et du langage C.


