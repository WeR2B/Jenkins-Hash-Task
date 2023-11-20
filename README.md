# Jenkins-Hash-Task
This code is meant to display any given words that are provided by the user. Program achieves this by storing each letter in linked list and looking for repeating hash values that way finding repeating word.

##Workflow
1. Program creates linked list with head as a pointer to whole list.
2. Program takes users input and checks if char value entered is between a to z and A to Z. If that condition is met character is send to append linked list. If input char is line feed (lf) or space char then program sends lf char that way storing words one line at a time.
3. Eventually after user input reaches EOF (End Of File) status, program enters hash_words function. There temp is assigned the same memory address as head and temp is used to go through linked list. Everytime linked list value is a letter char variable word[] gets assigned new char to make a completed word. This word array is then used to create hash and store it in temp->hash.
4. After each word was given the right hash it is sent to detect-repeating-hashes function. This function creates two linked list elements and goes through both of them to find hashes that are repeating. If repeating hash is found then it is stored in current->hash.
5. Printing of the linked list occures next. This is simply done by using temp pointer, going through whole linked list and cheking for lf char if that char is detected then temp->rep is shown on the screen else temp->value is shown.
6. And finally linked list is deleted from memory.

##Issues
1. This code needs hash table implementation. Hash table will allow for proper data output.
2. This code is missing help output.


