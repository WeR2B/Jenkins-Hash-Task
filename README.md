# Jenkins-Hash-Task
This code is meant to display any given words that are provided by the user. Program achieves this by storing each letter in linked list and looking for repeating hash values that way finding repeating word.

## Workflow
1. Program creates linked list with head as a pointer to the first node of a list.
2. Program takes users input checks if the input is a char with a value between A-Z or a-z. If it is then char are stored in word[] array until anything other then the value described is found. When anything other then A-Z or a-z is found program calculates hash value for that word, it checks for repeating words at the same time. And if a word has not been found yet it is sent append linked list.
3. Then program starts to print linked list. It does that by going though wgole list and finding words that have repeated at least once and that have not been printed.
4. Lastly program frees linked list.