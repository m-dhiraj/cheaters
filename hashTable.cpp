#include "hashTable.h"
unsigned int hashTable::hash(string s){
    unsigned int hashedValue=0;
    for(int i=0; i<s.length; i++){
        hashedValue+=((int)s.at(i));
        hashedValue*=i;
    }
    return hashedValue%MAX_SIZE;
}
void hashTable::addKey(unsigned int index, int fileLoc){
    if(t[index]==NULL)
    {
        t[index]=new Node;
        t[index]->index=fileLoc;
        t[index]->next=NULL;
    }
    Node* temp = t[index];
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node;
    temp->index=fileLoc;
    temp->next=NULL;
}
void hashTable::clear(){
    for(int i=0;i<MAX_SIZE;i++)
    {
        Node* temp = t[i];
        clearHelp(temp);
    }
}

void clearHelp(Node* s){
    if(s!=NULL)
        clearHelp(s->next);
    delete s;
    
}

