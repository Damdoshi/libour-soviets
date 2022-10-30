
Fonctions à réaliser issues de la LibC (principalement)
=======================================================

Toutes ces fonctions doivent être préfixées de our_

- strlen
- strnlen
- strcpy
- strncpy
- strlcpy
- strdup
- strndup
- strdupa - MACRO
- strndupa - MACRO
- strchr
- strrchr
- strchrnul
- strstr
- strnstr
- strcasestr
- strncasestr
- strcmp
- strncmp
- strcasecmp
- strncasecmp
- strcat
- strncat
- strlcat
- strcspn
- strpbrk
- strtok_r
- explode - PHP inspired function. Works like explode in PHP.
- implode - PHP inspired function. Works like implode in PHP, except it always take two parameters.
- strverscmp
- strfry
- basename
- dirname

- memcpy
- memchr
- memrchr
- memcmp
- memmem
- memdup
- memset
- memccpy
- memfrob

- strtol
- atoi
- strtod
- atof

- printbase -int our_printbase(int n, int base)
print the sent number and return how many characters were written. Maximum base is base 62 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz.

our_vector:
===========

typedef struct s_vector 

{ 
size_t capacity; // Capacité totale du vector en nombre d'éléments 
size_t nbr_elements; // Nombre d'éléments actuellement dans le vector 
size_t sizeof_data; // La taille en octet d'une seule donnée 
void *data; // Un tableau de capacity * sizeof_data octets 
} t_vector; 

#define our_vector_new(capacity, type) our_vector_news(capacity, sizeof(type))
t_vector our_vector_news(size_t capacity, size_t sizeof_data);
void our_vector_delete(t_vector *vec);

void *our_vector_push(t_vector *vec, void *data);
data doit mesurer sizeof_data. L'adresse renvoyée est celle de la zone mémoire ou a été copié data.
Une reallocation peut avoir lieu si besoin, mais seulement si besoin. NULL est renvoyé en cas d'erreur. En cas d'erreur, le vector original doit demeurer totalement intacte.

void our_vector_pop(t_vector *vec);

size_t our_vector_length(const t_vector *vec);
size_t our_vector_capacity(const t_vector *vec)
size_t our_vector_data_size(const t_vector *vec);

#define our_vector_get(vector, i, type) (type)our_vector_getv(vector, i)
void *our_vector_getv(t_vector *vec, size_t i);
NULL en cas d'erreur.

t_vector *our_vector_duplicate(const t_vector *vec);

void out_vector_sort(t_vector *vec, int (*cmp)());
Le vrai type de cmp étant une fonction prenant deux pointeurs en paramètres: les données à comparer.
Notez qu'en C, () est différent de (void), () signifiant "un nombre indeterminé de paramètre.

t_vector *out_vector_build(size_t sizeof_data, void *a, ...)
Construit un t_vector en utilisant les paramètres variadiques. NULL indique la fin des paramètres. NULL est renvoyé en cas d'erreur.
Une complexité de O(n) est attendue. Autrement dit, une seule reallocation est permise.

int our_vector_expand(t_vector *vec, void *a, ...)
Ajoute au vector en utilisant les paramètres variadiques. NULL indique la fin des paramètres. Une valeur de retour dont la valeur absolue est le nombre d'éléments ajouté et étant inférieur à zéro ou nul indique une erreur. Une valeur de retour positive indique un succès. Ce nombre devrait être le nombre d'éléments à ajouter passé;
int our_vector_expanda(t_vector *vec, void **array);
Une complexité de O(n) est attendue. Autrement dit, une seule reallocation est permise.

int our_vector_read(int fd, t_vector vec);
Lit tous les attributs du t_vector dans le fichier représenté par fd, à l'exception du void*.
Crée ensuite l'espace de stockage.
Lit ensuite les valeurs à stocker depuis le fichier.

int our_vector_write(int fd, t_vector vec);
Ecrit tous les attributs du t_vector dans le fichier représenté par fd, à l'exception du void*.
Ecrit ensuite les valeurs pointées par le void*.

our_vector2:
============

typedef struct s_size2_t
{
size_t x;
size_t y;
} t_size2_t;
typedef t_size2_t size2_t;

typedef struct s_vector2
{
size2_t capacity;
size2_t nbr_elements;
t_vector *vector;
} t_vector2;

#define our_vector2_new(xcapacity, ycapacity type) our_vector_news(xcapacity, ycapacity sizeof(type))
t_vector2 our_vector2_news(size_t xcapacity, size_t ycapacity size_t sizeof_data);

void our_vector2_delete(t_vector2 *vec);

int our_vector2_write(int fd, t_vector2 vec);
Ecrit tous les attributs du t_vector2 dans le fichier représenté par fd, à l'exception du t_vector.
Ecrit ensuite les valeurs contenues par le t_vector.

int our_vector2_read(int fd, t_vector2 vec);
Lit tous les attributs du t_vector2 dans le fichier représenté par fd, à l'exception du t_vector.
Crée ensuite un t_vector.
Lit ensuite les valeurs à stocker dans le t_vector depuis le fichier.

our_skiplist:
=============

Implementez la skiplist à deux niveaux déterministe suivante:

typedef struct s_skiplist_node
{
int index; // L'index n'a pas besoin d'etre
struct s_skiplist_node *next;
struct s_skiplist_node *prev;
void *data;
struct s_skiplist_node *next_skip;
struct s_skiplist_node *prev_skip;
} t_skiplist_node;

typedef struct s_skiplist
{
size_t len;
size_t skiplvl;
t_skiplist_node *begin;
t_skiplist_node *end;
} t_skiplist;

t_skiplist *our_skiplist_new(size_t skip);
void our_skiplist_delete(t_skiplist *skl);

t_skiplist_node *our_skiplist_push_front(t_skiplist *skl, void *data);
void *our_skiplist_pop_front(t_skiplist *skl);

t_skiplist_node *our_skiplist_push_back(t_skiplist *skl, void *data);
void *our_skiplist_pop_back(t_skiplist *skl);

// Must use next_skip and prev_skip to accellerate browsing.
t_skiplist_node *our_skiplist_insert(t_skiplist *skl, void *data, int index);
void *our_skiplist_remove(t_skiplist *skl, int index);
