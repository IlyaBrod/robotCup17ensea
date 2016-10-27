Commandes Git
=

### Initialisation #

* Configuration des couleurs dans la console

 `git config --global color.diff auto`  
 `git config --global color.status auto`    
 `git config --global color.branch auto`    

* Configuration de l'utilisateur

  `git config --global user.name "votre_pseudo"`  
  `git config --global user.email moi@email.com`  
 

* Importation/Création d'un git

  _Importer un github, (attention au dossier où vous vous trouvez)_  
  `git clone https://github.com/adresse`  
  _Création d'un git en local (attention au dossier)_  
  `git init`

---


### General #

* **Récupérer les modifications du serveur/voir les modifications locales**    
    * `git pull`  
    * `git status`  
      `git diff`  
      `git diff nomFichier`    

* **Ajouter/Supression un fichier au commit**  

    * `git add nomFichier`  
      `git add -a`  
    * `git reset HEAD --nomFichier`  

* **Faire un commit**  

  `git commit`  
  `git commit nomFichier1 nomFichier2`  
  `git commit -a`  

* **Afficher la liste des commmits** _(contrôle page up/down, Q : quitter)_  

  `git log`  
  `git log -p`  
  `git log --stat`  

---
### Partage avec le serveur #
* **Récupérer les modifications**  
    * `git pull`  
      _Récupère les dernières modifications et les fusionne avec les fichiers du projet. 
      Si un conflit apparait, le symbole <<<<< sera ajouté dans le fichier._
      
* **Envoyer/Inverser la modification d'un commit au serveur**
    * `git push`  
      _Toujours faire un pull avant_  
    * `git revert ID_du_commit`  
      _A éviter_  

* **Ajouter/Supprimmer un numéro de version à un commit**
   * `git tag nomTag ID_du_commit`  
`      git push --tags`  
   * `git tag -d nomTag`

---
### Gestion des erreurs #
* **Modifier le message du commit**
  * `git commit --amend`  

* **Annuler un commit sans modifier les fichier/en restaurant les fichiers**  
  _HEAD = dernier commit, HEAD^ = avant dernier commit etc..._
  *  `git reset HEAD^`  
`   git reset HEAD^^`  
   `git reset ID_du_commit`  
  * `git reset --hard HEAD^`  

* **Restauration du fichier au dernier commit**
  * `git checkout nomFichier` 
 
---
### Gestion des branches #
* **Se situer/se déplacer**
  * `git branch`
  * `git checkout nomBranche`

* **Créer une branche/Supprimmer/Fusionner**
  * `git branch nomBranche`
  * `git branch -d nomBranche`  
    `git branch -D nomBranche`  
   _-D force la suppression sans vérifier la fusion de la branche_
  * `git merge nomBranche`  
    _Il faut se trouver dans la branche dans laquelle on fusionne_  

* **Mettre de côté/Revenir dans une branche**
  * `git stash`
  * `git stash apply`

* **Partage de branche sur le serveur**
  * Afficher/Récupération d'une branche  
    * `git branch -r`
    * `git branch --track nomLocal origin/nomServeur`
  * Ajouter/Supprimmer une branche du serveur  
    * `git push origin origin:refs/heads/nomBranche`  
    * `git push origin :heads/nomBranche`  
      _Chaque client doit la supprimmer en local_

---

_Auteur : 
BRODOLINE Ilya_
