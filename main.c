#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

float secondDegre(int a, int b, int c){

    float delta=0,x0=0,x1=0,x2=0, reelle=0;
    double imaginaire=0;

    if(a !=  0 && a != 1){
        printf("L'equation du second degre est: ");
        printf("%dx^2 ",a);
    }else{
        if(a == 1){
            printf("L'equation du second degre est: ");
            printf("x^2 ");
        }else{
            printf("Ce n'est pas une equation du second degre \n");
        }
    }
    if(b!=0){
        if(b > 0){
            printf("+");
        }
        printf("%dx ",b);
    }
    if(c!=0){
        if(c > 0){
            printf("+");
        }
        printf("%d",c);
    }
    printf(" = 0\n");
    delta=b*b -4*a*c;
    printf("Son determinant est: %f\n",delta);
    if(delta <0){
        printf("L'equation n'a pas de solution dans |R\n");
        printf("l'equation a deux solutions compexes dans C: \n");
        reelle=(float)(-b)/(2*a);
        printf("%f\n",reelle);
        printf("reelle = %f\n",reelle);
        imaginaire=(float)sqrt(-delta)/(2*a);
        printf("imaginaire = %f\n",imaginaire);
        printf("%f  %f*i et %f + %f*i \n",reelle,-imaginaire,reelle,imaginaire);
    }else{
        if(delta ==0){
            x0=-b/(2*a);
           printf("L'equation a une solution double: %f\n",x0);
        }else{
           x1=(-b-sqrt(delta))/(2*a);
           x2=(-b+sqrt(delta))/(2*a);
           printf("L'equation a deux solutions distinctes: %f et %f\n",x1,x2);
        }
    }
    return(delta);
}

float aire(float largeur,float longueur){
    float aire = largeur *longueur;

    return(aire);
}

float volume(float largeur,float longueur,float hauteur){
    float volume = largeur *longueur*hauteur;

    return(volume);
}

float perimetre(float rayon){
    float perimetre = 2 * M_PI * rayon;

    return(perimetre);
}


float aireCercle(float rayon){
    float aireCercle = (4/3) * M_PI * rayon;

    return(aireCercle);
}

int main()
{   /*
    int a = 0, b= 0,c = 0;
    printf("Equation du second degre:\n");
    printf("Saisissez le nombre de degre 2:\n");
    scanf("%d",&a);
    printf("Saisissez le nombre de degre 1:\n");
    scanf("%d",&b);
    printf("Saisissez le nombre de degre 0:\n");
    scanf("%d",&c);

    printf("Le discriminant vaut: %f",secondDegre(a,b,c));*/
       /*aire et volume  */
    /*float largeur = 0, longueur= 0,hauteur = 0;

    printf("Entrez la largeur:\n");
    scanf("%f",&largeur);
    printf("Entrez la longueur:\n");
    scanf("%f",&longueur);
    printf("Entrez la hauteur:\n");
    scanf("%f",&hauteur);

    printf("L'aire vaut %f cm^2 et le volume vaut %f cm^3\n",aire(largeur,longueur),volume(largeur,longueur,hauteur));


    /* disque cercle*/
    /* float rayon;
    printf("Entrez le rayon du cercle:\n");
    scanf("%f",&rayon);*/
    //perimetre et aire
    /* printf(" le perimetre du cercle de rayon %f est de %f cm et son aire est de %f cm^2 \n",rayon,perimetre(rayon),aireCercle(rayon));
    */

    char partieGauche[50],partieDroite[50],tabSymboles[20],tabInconnues[20], nouveauNb[20];
    printf("Saisissez la partie gauche de l'equation: \n");
    scanf("%s",partieGauche);
    printf("La longueur de la partie gauche de l'equation est de %d lettres \n",strlen(partieGauche));
        printf("Saisissez la partie droite de l'equation: \n");
    scanf("%s",partieDroite);


    double tabNbGauche[20]={0},tabNbDroite[20]={0};
    int cptSymbolesGauche=0, cptInconnuesGauche=0,nbChiffres=0,cpt,i,posNb=0,cptNb=0;
    for( cpt = 0;cpt < strlen(partieGauche);cpt++){

        if(partieGauche[cpt]=='+'||partieGauche[cpt]=='-'||partieGauche[cpt]=='*'||partieGauche[cpt]=='/'){
            printf("detection d'un operateur: %c \n",partieGauche[cpt]);
            tabSymboles[cptSymbolesGauche]=partieGauche[cpt];
            printf("Affichage du symbole une fois entre dans la table:  %c a la position %d \n",tabSymboles[cptSymbolesGauche],cptSymbolesGauche);
            cptSymbolesGauche++;
            printf("nbChiffres avant la verification non nulle: %d \n",nbChiffres);
            if(nbChiffres != 0){
                printf("nbChiffres non nul \n");
                for(i= nbChiffres;i > 0; i--){
                    nouveauNb[cptNb]=partieGauche[cpt-i];
                    //printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %d\n",i,atoi(partieGauche[cpt-i]));
                    printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %c et de nouveauNb %c et le nouveauNB complet vaut %s \n",i,partieGauche[cpt-i],nouveauNb[cptNb],nouveauNb);
                    cptNb++;
                }
                cptNb=0;
                printf("Affichage du nombre avant d'entrer dans la table: %f \n",atof(nouveauNb));
                tabNbGauche[posNb]=atof(nouveauNb);
                printf("Affichage du nombre une fois entre dans la table: %f  etat de posNb %d\n",tabNbGauche[posNb],posNb);
                posNb++;
                nbChiffres=0;
            }
        }else{

            if(isalpha(partieGauche[cpt])&& partieGauche[cpt]!= ','){
                printf("Detection d'une inconnue: %c \n",partieGauche[cpt]);
                tabInconnues[cptInconnuesGauche]=partieGauche[cpt];
                printf("Affichage de l'inconnue une fois entree dans la table: %c  a la position %d \n",tabInconnues[cptInconnuesGauche],cptInconnuesGauche);
                cptInconnuesGauche++;
                if(nbChiffres != 0){
                    printf("nbChiffres non nul \n");
                    for(i= nbChiffres;i > 0; i--){
                        nouveauNb[cptNb]=partieGauche[cpt-i];
                        //printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %d\n",i,atoi(partieGauche[cpt-i]));
                        printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %c et de nouveauNb %c et le nouveauNB complet vaut %s \n",i,partieGauche[cpt-i],nouveauNb[cptNb],nouveauNb);
                        cptNb++;
                    }
                    cptNb=0;
                    printf("Affichage du nombre avant d'entrer dans la table: %f \n",atof(nouveauNb));
                    tabNbGauche[posNb]=atof(nouveauNb);
                    printf("Affichage du nombre une fois entre dans la table: %f  etat de posNb %d\n",tabNbGauche[posNb],posNb);
                    posNb++;
                    nbChiffres=0;
               }
            }else{
                 if(partieGauche[cpt +1]=='\0'){
                     if(nbChiffres != 0){
                            printf("Detection d'un chiffre: %c \n",partieGauche[cpt]);
                            printf("nbChiffres vaut: %d \n",nbChiffres);
                            nbChiffres++;
                            printf("nbChiffres vaut: %d \n",nbChiffres);
                            printf("nbChiffres non nul \n");
                            for(i= nbChiffres;i > 0; i--){
                                nouveauNb[cptNb]=partieGauche[cpt+1-i];
                                //printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %d\n",i,atoi(partieGauche[cpt-i]));
                                printf("Affichage de l'etat du compteur %d ainsi que de l'element de la partieGauche %c et de nouveauNb %c et le nouveauNb complet vaut %s \n",i,partieGauche[cpt+1-i],nouveauNb[cptNb],nouveauNb);
                                cptNb++;
                        }
                        cptNb=0;
                        printf("Affichage du nombre avant d'entrer dans la table: %f \n",atof(nouveauNb));
                        tabNbGauche[posNb]=atof(nouveauNb);
                        printf("Affichage du nombre une fois entre dans la table: %f etat de posNb %d\n",tabNbGauche[posNb],posNb);
                        posNb++;
                        nbChiffres=0;
                    }
                }else{
                    printf("Detection d'un chiffre: %c \n",partieGauche[cpt]);
                    printf("nbChiffres vaut: %d \n",nbChiffres);
                    nbChiffres++;
                    printf("nbChiffres vaut: %d \n",nbChiffres);
                }
            }

        }
    }
    printf("L'ensemble des inconnues relevees est: \n");
    for(i =0; i < cptInconnuesGauche;i++){
        if(i == 0){
            printf(" %c",tabInconnues[0]);
        }else{
             if(tabInconnues[i] != '\0'){
                printf(" ,%c i = %d",tabInconnues[i],i);
            }else{
                printf(" %c i = %d\n",tabInconnues[i],i);
            }
        }
    }
    printf(" \n L'ensemble des Symboles releves est:\n");
    for(i = 0; i < cptSymbolesGauche ;i++){
        if(i == 0){
            printf(" %c",tabSymboles[0]);
        }else{
            if(tabSymboles[i] != '\0'){
                printf(" ,%c i = %d",tabSymboles[i],i);
            }else{
                printf(" %c i = %d \n",tabSymboles[i], i);
            }
        }
    }
        printf("\n L'ensemble des nombres releves est: \n");
    for(i =0; i < posNb;i++){
        if(i == 0){
            printf(" %f i=%d ",tabNbGauche[0],i);
        }else{
             if(tabNbGauche[i] != 0){
                printf(" ,%f i=%d",tabNbGauche[i],i);
            }else{
                printf(" %f i= %d\n",tabNbGauche[i],i);
            }
        }
    }
    printf("\n L'equation est: %s = %s ",partieGauche,partieDroite);

    printf("\n L'ensemble des elements de la partie gauche de l'equation est: \n");
    for(i =0; i < sizeof(partieGauche);i++){
        if(i == 0){
            printf(" %c",partieGauche[0]);
        }else{
             if(partieGauche[i] != '\0'){
                printf(" ,%c",partieGauche[i]);
            }else{
                printf(" %c \n",partieGauche[i]);
                i = sizeof(partieGauche);
            }
        }
    }
    return 0;
}
