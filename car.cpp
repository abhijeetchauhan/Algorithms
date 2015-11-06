#include <iostream>
using namespace std;
struct Driver{
  string name;
  int id;
};
struct LinkedTaxi
{
  int id;
  Driver *drv;
  LinkedTaxi *next;
};
struct Queue
{
  LinkedTaxi *front,*end;
  int numTaxis;
};
int main(){
  Queue q;
  q.front=NULL;q.end=NULL;q.numTaxis=0;
  while(true){
    cout << "Command: 'j' to join Queue,'d' to dispatch,'x' to exit ." << endl;
    char Command;
    cin >> Command;
    switch(Command){
      case 'j': Driver *newDrv;newDrv=new Driver;
                if(newDrv==NULL){
                  cout << "Not sufficient memory!!";
                  return -1;
                }
                cout << "Give name of the driver: ";
                cin >> newDrv->name;
                cout << "Give id of the driver: ";
                cin >> newDrv->id;
                LinkedTaxi *newTaxi;newTaxi=new LinkedTaxi;
                if(newTaxi==NULL){
                  cout << "Not sufficient memory !!!";
                  return -1;
                }
                newTaxi->drv=newDrv;newTaxi->next=NULL;
                cout << "Give id of the taxi: ";
                cin >> newTaxi->id;
                if(q.end==NULL){
                  q.front=newTaxi;q.end=newTaxi;q.numTaxis=1;
                }
                else{
                  (q.end)->next=newTaxi;q.end=newTaxi;q.numTaxis++;
                }
                break;
      case 'd': if(q.front==NULL){
                  cout << "Sorry! No taxis in Queue are present!" << endl;
                }
                else{
                  LinkedTaxi *dispatchTaxi;dispatchTaxi=q.front;
                  if(q.front==q.end){
                    q.front =NULL;q.end=NULL;q.numTaxis=0;
                  }
                  else{
                    q.front=(q.front)->next; q.numTaxis--;
                  }
                  if(dispatchTaxi != NULL){
                    cout << "Dispatching taxi with id " << dispatchTaxi->id << endl ;
                    if(dispatchTaxi->drv!=NULL){
                      delete dispatchTaxi->drv;
                    }
                    delete dispatchTaxi;
                  }
                }
                break;
      case 'x':cout << "Thank you" << endl ;return 0;
      default: cout << "Invalid command." << endl;
    }
  }

  return 0;
}