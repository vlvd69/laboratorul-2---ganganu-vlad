#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Facultati {
    char denumirea[50];
    int nrDeStudenti;
    int nrDeGrupe;
    int nrAniDeStudii;
    int nrDeExamene;
    int nrDeEvaluariPeriodice;
};

struct Node {
    struct Facultati f;
    struct Node* link;
};

void afisareLista(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("Denumirea: %s\n", current->f.denumirea);
        printf("Numar de studenti: %d\n", current->f.nrDeStudenti);
        printf("Numar de grupe: %d\n", current->f.nrDeGrupe);
        printf("Numar de ani de studii: %d\n", current->f.nrAniDeStudii);
        printf("Numar de examene: %d\n", current->f.nrDeExamene);
        printf("Numar de evaluari periodice: %d\n", current->f.nrDeEvaluariPeriodice);
        printf("---------------------------------\n");
        current = current->link;
    }
}

void cautare(struct Node *head, int data, int elemente) {
    struct Node *ptr;
    ptr = head;
    int count = 0;
    for (int i = 0; i < elemente; i++) {
        count++;
        if (ptr->f.nrAniDeStudii == data) {
            break;
        }
        ptr = ptr->link;
    }
    printf("\nFacultatea gasita este Numarul %d", count);
    printf("\nDenumirea: %s", ptr->f.denumirea);
    printf("\nAni de strudii: %d", ptr->f.nrAniDeStudii);
    printf("\nNumarul de studenti: %d", ptr->f.nrDeStudenti);
    printf("\nNumarul de grupe: %d", ptr->f.nrDeGrupe);
    printf("\nNumarul de examene: %d", ptr->f.nrDeExamene);
    printf("\nNumarul de evaluari periodice: %d \n\n", ptr->f.nrDeEvaluariPeriodice);
}

void sortare(struct Node *head, int lung) {
    struct Node *ptr;
    struct Node *next;
    struct Facultati temp;

    for (int j = 0; j < lung; j++) {
        ptr = head;
        next = head->link;

        for (int i = 0; i < lung - 1; i++) {
            if (ptr->f.nrDeExamene > next->f.nrDeExamene) {
                temp = next->f;
                next->f = ptr->f;
                ptr->f = temp;
            }
            ptr = ptr->link;
            next = next->link;
        }
    }
}

void addLaCapat(struct Node *head, struct Facultati tempor) {
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp != NULL) {
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        temp->f = tempor;
        ptr->link = temp;
        temp->link = NULL;

        printf("\nFacultate noua adaugata cu succes\n");
    } else {
        printf("\nEroare la alocarea memoriei\n");
    }
}

void addLaInceput(struct Node **head, struct Facultati tempor) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp != NULL) {
        temp->f = tempor;
        temp->link = *head;
        *head = temp;

        printf("\nFacultate noua adaugata cu succes\n");
    } else {
        printf("\nEroare la alocarea memoriei\n");
    }
}

void addLaPozitie(struct Node *head, struct Facultati tempor, int poz) {
    struct Node *ptr = head;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    int count = 2;
    while (ptr != NULL && poz != count) {
        ptr = ptr->link;
        count++;
    }

    if (ptr != NULL) {
        temp->f = tempor;
        temp->link = ptr->link;
        ptr->link = temp;

        printf("\nFacultate noua adaugata cu succes\n");
    } else {
        printf("\nPozitie invalida pentru inserare\n");
    }
}



void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

void stergereLaPoz(struct Node *head, int poz) {
    if (poz == 1) {
        struct Node *temp = head;
        head = head->link;
        free(temp);
        printf("\nElement sters de la pozitia %d.\n", poz);
        return;
    }
    struct Node *current = head;
    struct Node *prev = NULL;
    int count = 1;
    while (current != NULL && count != poz) {
        prev = current;
        current = current->link;
        count++;
    }
    if (current == NULL) {
        printf("\nPozitie invalida pentru stergere.\n");
        return;
    }
    prev->link = current->link;
    free(current);
    printf("\nElement sters de la pozitia %d.\n", poz);
}

void inversare(struct Node **headRef) {
    struct Node *prev = NULL;
    struct Node *current = *headRef;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int optiune;
    int poz,elemente,lung;
    int nrAniDeStudii;
    printf("\nMeniu:\n");
    printf("1. Citirea datelor\n");
    printf("2. Afisare elemente\n");
    printf("3. Cautare element\n");
    printf("4. Eliberare memorie\n");
    printf("5. Sortarea elementelor\n");
    printf("6. Inserare la capat\n");
    printf("7. Inserare la inceput\n");
    printf("8. Inserare la o anumita pozitie\n");
    printf("9. Stergere element de la o anumita pozitie\n");
    printf("10. Inversare lista\n");
    printf("0. Iesire\n");

    do {
        printf("Introduceti optiunea: ");
        scanf("%d", &optiune);
        switch (optiune) {
            case 1: {
                struct Facultati t;
                printf("Introduceti denumirea facultatii: ");
                scanf("%s", t.denumirea);
                printf("Introduceti numarul de studenti: ");
                scanf("%d", &t.nrDeStudenti);
                printf("Introduceti numarul de grupe: ");
                scanf("%d", &t.nrDeGrupe);
                printf("Introduceti numarul de ani de studii: ");
                scanf("%d", &t.nrAniDeStudii);
                printf("Introduceti numarul de examene: ");
                scanf("%d", &t.nrDeExamene);
                printf("Introduceti numarul de evaluari periodice: ");
                scanf("%d", &t.nrDeEvaluariPeriodice);

                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                if (newNode == NULL) {
                }
                newNode->f = t;
                newNode->link = NULL;

                if (head == NULL) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->link = newNode;
                    tail = newNode;
                }
                break;
            }
            case 2: {
                printf("Lista Facultatilor.\n");
                afisareLista(head);
                break;
            }
            case 3: {
                printf("Introduceti numarul de ani de studii:\n");
                scanf("%d",&nrAniDeStudii);
                cautare(head,nrAniDeStudii,elemente);
                break;
            }
            case 4: {
                freeList(head);
                printf("Memorie eliberata cu succes.\n");
                break;
            }
            case 5: {
                sortare(head,elemente);
                printf("Sortarea duna numarul de examene efectuata cu succes.\n");
                break;
            }
            case 6: {
                struct Facultati t;
                printf("Introduceti denumirea facultatii: ");
                scanf("%s", t.denumirea);
                printf("Introduceti numarul de studenti: ");
                scanf("%d", &t.nrDeStudenti);
                printf("Introduceti numarul de grupe: ");
                scanf("%d", &t.nrDeGrupe);
                printf("Introduceti numarul de ani de studii: ");
                scanf("%d", &t.nrAniDeStudii);
                printf("Introduceti numarul de examene: ");
                scanf("%d", &t.nrDeExamene);
                printf("Introduceti numarul de evaluari periodice: ");
                scanf("%d", &t.nrDeEvaluariPeriodice);
                 addLaCapat(head,t);
                elemente++;
                break;
            }
            case 7: {
                struct Facultati t;
                printf("Introduceti denumirea facultatii: ");
                scanf("%s", t.denumirea);
                printf("Introduceti numarul de studenti: ");
                scanf("%d", &t.nrDeStudenti);
                printf("Introduceti numarul de grupe: ");
                scanf("%d", &t.nrDeGrupe);
                printf("Introduceti numarul de ani de studii: ");
                scanf("%d", &t.nrAniDeStudii);
                printf("Introduceti numarul de examene: ");
                scanf("%d", &t.nrDeExamene);
                printf("Introduceti numarul de evaluari periodice: ");
                scanf("%d", &t.nrDeEvaluariPeriodice);
                addLaInceput(&head,t);
                elemente++;
                break;
            }
            case 8: {
                printf("Introduceti pozitia la care doriti inserarea:\n");
                scanf("%d", &poz);
                struct Facultati p;
                printf("Introduceti denumirea facultatii: ");
                scanf("%s", p.denumirea);
                printf("Introduceti numarul de studenti: ");
                scanf("%d", &p.nrDeStudenti);
                printf("Introduceti numarul de grupe: ");
                scanf("%d", &p.nrDeGrupe);
                printf("Introduceti numarul de ani de studii: ");
                scanf("%d", &p.nrAniDeStudii);
                printf("Introduceti numarul de examene: ");
                scanf("%d", &p.nrDeExamene);
                printf("Introduceti numarul de evaluari periodice: ");
                scanf("%d", &p.nrDeEvaluariPeriodice);
                addLaPozitie(head, p, poz);
                elemente++;
                break;
            }
            case 9: {
                printf("Introduceti pozitia de la care doriti sa stergeti:\n");
                scanf("%d", &poz);
                stergereLaPoz(head, poz);
                elemente--;
                break;
            }
            case 10: {
                inversare(&head);
                printf("Lista inversata cu succes:\n");
                break;
            }
            case 0: {
                printf("Programul s-a inchis.\n");
                break;
            }
            default: {
                printf("Optiune invalida! Va rugam sa introduceti o optiune valida.\n");
                break;
            }
        }
    } while (optiune != 0);
    return 0;
}
