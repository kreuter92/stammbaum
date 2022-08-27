#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TOTAL_MEMBERS 4

typedef struct Node
{
    char name[30];
    char birthday[11];
    char deathday[11];
    char gender[2];
    char birthplace[30];
    char partner[30];
    struct Node *sibling;
    struct Node *child;
} Node;

// Creating new Node
Node * newNode(char *name, char *birthday, char *deathday, char *gender, char *birthplace, char *partner)
{
    Node *newNode = malloc(sizeof(*newNode));
    newNode->sibling = newNode->child = NULL;
    strcpy(newNode->name, name);
    strcpy(newNode->birthday, birthday);
    strcpy(newNode->deathday, deathday);
    strcpy(newNode->gender, gender);
    strcpy(newNode->birthplace, birthplace);
    strcpy(newNode->partner, partner);
    printf("%s\n", newNode->birthday);
    return newNode;
}

// Adds a sibling to a list with starting with n
Node *addSibling(Node *n, char *name, char *birthday, char *deathday, char *gender, char *birthplace, char *partner)
{
    if (n == NULL)
        return NULL;

    while (n->sibling)
        n = n->sibling;

    return (n->sibling = newNode(name, birthday, deathday, gender, birthplace, partner));
}

// Add child Node to a Node
Node *addChild(Node * n, char *name, char *birthday, char *deathday, char *gender, char *birthplace, char *partner)
{
    if (n == NULL)
        return NULL;

    // Check if child list is not empty.
    if (n->child)
        return addSibling(n->child, name, birthday, deathday, gender, birthplace, partner);
    else
        return (n->child = newNode(name, birthday, deathday, gender, birthplace, partner));
}

int main()
{
    Node *tree[TOTAL_MEMBERS];
    tree[0] = newNode("Elli", "25.04.1925", "04.07.2008", "w", "Louisenwerth", "Heinz");
    tree[1] = addChild(tree[0], "Ulrike", "19.05.1954", " ", "w", "Essen", "Rainer");
    tree[2] = addChild(tree[0], "Franz", "22.05.1958", " ", "m", "Weimar", " ");
    tree[3] = addChild(tree[1], "Kristina", "05.09.1992", " ", "w", "Haltern am See", " ");
    /*
    Node *n1  = addChild(n0, "Ulrike", "19.05.1954", " ", "w", "Essen", "Rainer");
    Node *n2  = addChild(n0, "Franz", "22.05.1945", " ", "m", "Weimar", " ");
    Node *n3  = addChild(n1, "Kristina", "05.09.1992", " ", "w", "Haltern am See", " ");
    */
   
    FILE *outfile;
    outfile = fopen("person.txt", "w");
    if (outfile == NULL)
    {
	    fprintf(stderr, "\nERROR: file is opened\n");
	    exit(1);
    }
    for (int i = 0; i < TOTAL_MEMBERS; i++){
	    fprintf(outfile, "%s,%s,%s,%s,%s,%s,%s,%s\n", 
		   tree[i]->name, 
		   tree[i]->birthday, 
		   tree[i]->deathday, 
		   tree[i]->gender,
		   tree[i]->birthplace,
		   tree[i]->partner,
		   tree[i]->sibling->name,
		   tree[i]->child->name);
    }
    /*
    fwrite (n0, sizeof(Node), 1,  outfile);
    fwrite("\n", sizeof(char), 1, outfile);
    fwrite (n1, sizeof(Node), 1, outfile);
    fwrite("\n", sizeof(char), 1, outfile);
    fwrite (n2, sizeof(Node), 1, outfile);
    fwrite("\n", sizeof(char), 1, outfile);
    fwrite (n3, sizeof(Node), 1, outfile);
    */
    if (fwrite != 0)
	    printf("contents to file written successfully!\n");
    else
	    printf("error writing file!\n");
    fclose (outfile);
    return 0;
}
