#include "hashTable.h"
#include "numArray.h"
hashTable::hashTable(){
    for(int i=0;i<MAX_SIZE;i++){
        t[i]=NULL;
    }
}
unsigned int hashTable::hash(string s){
    unsigned int hashedValue=0;
    for(int i=0; i<s.length(); i++){
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
int** hashTable::getMatrix(int files){
    numArray matrix(6);
    for(int i=0;i<MAX_SIZE;i++){
        Node* rowPtr=t[i];
        while(rowPtr!=NULL){
            int row=rowPtr->index;
            Node* colPtr=rowPtr->next;
            while (colPtr!=NULL)
            {
                matrix.incValue(rowPtr->index,colPtr->index);
                colPtr=colPtr->next;
            }
            Node* temp=rowPtr->next;
            while (temp!=NULL && temp->index==rowPtr->index)
            {
                temp=temp->next;
            }
            rowPtr=temp;
        }
    }
    return NULL;
}
void hashTable::clear(){
    for(int i=0;i<MAX_SIZE;i++)
    {
        Node* temp = t[i];
        clearHelp(temp);
    }
}

void hashTable::clearHelp(Node* s){
    if(s!=NULL)
        clearHelp(s->next);
    delete s;
    
}
hashTable::~hashTable(){
    clear();
}
