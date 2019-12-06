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
    //cout<<index<<endl;
    if(t[index]==NULL)
    {
        t[index]=new Node;
        t[index]->index=fileLoc;
        t[index]->next=NULL;
        //cout<<t[index]->index<<endl;
    }
    if(t[index]!=NULL){
    Node* temp = t[index];
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new struct Node;
    temp=temp->next;
    temp->index=fileLoc;
    temp->next=NULL;
    }
    
}
int** hashTable::getMatrix(int files){
    numArray matrix(files);
    for(int i=0;i<MAX_SIZE;i++){
        //cout<<t[i]->fNames.size()<<endl;
        Node* rowPtr=t[i];
        while(rowPtr!=NULL){
            int row=rowPtr->index;
            
            Node* colPtr=t[i]->next;
            if(colPtr!=NULL){
                //cout<<colPtr->index<<endl;
            }
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
            int r=files;
            int** array = new int*[r];
            for(int i=0; i<r; i++){
                array[i]=new int[r];
            }
            for(int i=0;i<r;i++)
                for(int g=0;g<r;g++)
                {
                    array[i][g]=matrix.getValue(i,g);
                    //cout<<matrix.getValue(i,g)<<endl;
                }


    return array;
}
void hashTable::clear(){
    for(int i=0;i<MAX_SIZE;i++)
    {
       // t[i]->fNames.clear();
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
