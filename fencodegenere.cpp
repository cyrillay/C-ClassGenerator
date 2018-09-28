#include "fencodegenere.h"
#include "fenprincipale.h"


fencodegenere::fencodegenere(QString* code) : QWidget() //appeller le constructeur de QWidget
{

this->resize(400,500);

    m_layout = new QVBoxLayout;
    //m_layout->setContentsMargins(100,100,100,100);

        //Champ de texte
        m_texte = new QTextEdit(this);
        m_texte->setFont(QFont("Courier"));
        m_texte->setPlainText(*code);

        //Bouton fermer
        m_bout1 = new QPushButton("Fermer",this);
        m_bout1->connect(m_bout1,SIGNAL(clicked(bool)),this,SLOT(close()));

        //Bouton sauvegarder
        m_bout2 = new QPushButton("Sauvegarder",this);
        m_bout2->connect(m_bout2,SIGNAL(clicked(bool)),this,SLOT(sauvegarder()));

    m_layout->addWidget(m_texte);
    m_layout->addWidget(m_bout1);
    m_layout->addWidget(m_bout2);
    this->setLayout(m_layout);

}

void fencodegenere :: sauvegarder()
{
    //choix du dossier d'enregistrement
    QString chemin = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", "" , "Fichier texte (*.txt)");
    // "" sert à ouvrir par défaut le répertoire de l'exécutable


    //Ouverture du fichier
    QFile fichier(chemin);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);

    //Ecriture dans le fichier
    QTextStream flux(&fichier);
    flux << m_texte->toPlainText();

    //Fermeture
    fichier.close();
}
