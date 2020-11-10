#ifndef CHAIN_H
#define CHAIN_H                       
                                      
template <class T>                    
class node                            
{                                     
  public:                             
    T data;                           
    node *next;
    node(T data)
    {
      this->data = data;
    }
};                                    
                                      
                                      
template <class T>                    
class chain                           
{                                     
  public:                             
    node<T> *head;                    
    node<T> *tail;                    
    int position;                     
  public:                             
    chain()                           
    {                                 
      head = tail = NULL;             
    }                                 
    ~chain()                          
    {                                 
      delete head;                    
      delete tail;                    
    };                                
                                      
    void insert(T data)                
    {                                  
      if (head == NULL)                
      {                                
        head = tail = new node<T>(data);  
        head->next = NULL;             
        tail->next = NULL;             
      }                                
      else                             
      {                                
        node<T>* p  = new node<T>(data);     
        tail->next = p;                
        tail = p;                      
        tail->next = NULL;             
      }                                
    }                                  
                     
    void delete()
};                                      
                                       
#endif                                 