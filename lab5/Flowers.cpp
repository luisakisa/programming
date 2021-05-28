#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Flower
{
    double cost;
    string color;
    int quantity;
    string kind;
};
 
struct DLList
{
    struct Node
    {
        Flower data;     //information
        Node* next;   //next node position
        Node* prev;   //previous node position
    };

    Node* F = NULL;     //first node
    Node* L = NULL;     //last node
    Node* C = NULL;     //current node
    int Count;        //node count

    void Out();
    void Info();
    void Clear();

    bool MoveNext();
    bool MovePrev();
    bool MoveFirst();
    bool MoveLast();

    bool Init(Flower);
    bool AddNext(Flower);
    bool AddPrev(Flower);
    bool AddFirst(Flower);
    bool AddLast(Flower);

    bool Del(Flower&);
    bool DelNext(Flower&);
    bool DelPrev(Flower&);
    bool DelFirst(Flower&);
    bool DelLast(Flower&);
};

bool DLList::MoveNext()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->next) return false;
    C = C->next;
    return true;
}

bool DLList::MovePrev()
{
    if (!F)       return false;
    if (!C) { C = F; return true; }
    if (!C->prev) return false;
    C = C->prev;
    return true;
}
bool DLList::MoveFirst()
{
    if (!F) return false;
    C = F;
    return true;
}

bool DLList::MoveLast()
{
    if (!L) return false;
    C = L;
    return true;
}

bool DLList::Init(Flower data)
{
    if (!F)
    {
        F = new Node;
        L = F;
        C = F;
        F->prev = NULL;
        F->next = NULL;
        F->data = data;
        Count = 1;
        return true;
    }
    else
        return false;
}

bool DLList::AddNext(Flower data)
{
    if (!F) return Init(data);

    Node* temp = C->next;
    C->next = new Node;
    C->next->next = temp;
    C->next->prev = C;

    if (!temp)
        L = C->next;
    else
        temp->prev = C->next;

    C = C->next;
    C->data = data;
    Count++;
    return true;

}

bool DLList::AddPrev(Flower data)
{
    if (!F) return Init(data);

    Node* temp = C->prev;
    C->prev = new Node;
    C->prev->next = C;
    C->prev->prev = temp;

    if (!temp)
        F = C->prev;
    else
        temp->next = C->prev;

    C = C->prev;
    C->data = data;
    Count++;
    return true;
}

bool DLList::AddFirst(Flower data)
{
    if (MoveFirst())return AddPrev(data);
    else return false;
}

bool DLList::AddLast(Flower data)
{
    if (MoveLast())return AddNext(data);
    else return false;
}

void DLList::Out()
{
    if (!F)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = F;
    cout << "List: " << endl << endl;
    do
    {
        cout << temp->data.color << " "<< temp->data.cost << " "<< temp->data.kind << " "<< temp->data.quantity << endl;
        temp = temp->next;
    } while (temp);
    cout << endl;
}

void DLList::Info()
{

    if (Count)
        cout << "List node count: "
        << Count << endl << endl;
    else
        cout << "List is empty" << endl;
    if (C)
    {
        if (MoveFirst())
        {
            cout << "Current node data: ";
            cout << C->data.color << " "<< C->data.cost << " "<< C->data.kind << " "<< C->data.quantity << endl;
        }
    }
}

bool DLList::DelFirst(Flower& data)
{
    if (!F)      return false;
    if (C != F)    MoveFirst();

    Node* temp = C->next;
    data = C->data;

    if (temp) temp->prev = NULL;
    delete C;

    C = temp;
    F = temp;
    Count--;
    if (!temp) { L = NULL; return false; }
    return true;
}

bool DLList::DelLast(Flower& data)
{
    if (!F)      return false;
    if (C != L)    MoveLast();

    Node* temp = C->prev;
    data = C->data;

    if (temp) temp->next = NULL;
    delete C;

    C = temp;
    L = temp;
    Count--;

    if (!temp) { F = NULL; return false; }
    return true;
}

bool DLList::Del(Flower& data)
{
    if (!F) return false;
    if (!C) return false;

    if (C == F) return DelFirst(data);
    if (C == L) return DelLast(data);

    Node* temp = C->next;
    data = C->data;

    C->prev->next = C->next;
    C->next->prev = C->prev;

    delete C;
    C = temp;
    Count--;
    return true;
}

bool DLList::DelNext(Flower& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MoveNext()) return Del(data);
    return false;
}
bool DLList::DelPrev(Flower& data)
{
    if (!F) return false;
    if (!C) return false;
    if (MovePrev()) return Del(data);
    return false;
}

void DLList::Clear()
{
    if (!MoveFirst())
    {
        cout << "List is empty" << endl;
        return;
    }
    Flower k;
    while (Del(k));
}
bool GetFile(DLList&, Flower&);
bool WriteFile(DLList&, Flower&);
void GetFlower(Flower&);

bool GetFile(DLList& DLList, Flower& Info)
{
    ifstream F("Flowers.txt");
    if (!F)
    {
        cout << "File not found" << endl;
        return false;
    }
    while (F >> Info.color >> Info.cost >> Info.kind >> Info.quantity)
    {
        DLList.AddNext(Info);
    }
    F.close();
    return true;
}

bool WriteFile(DLList& DLList, Flower& Info)
{
    ofstream File("Flowers.txt");
    DLList.MoveFirst();
    do
    {
        File << DLList.C->data.color << " " << DLList.C->data.cost << " " << DLList.C->data.kind << " " << DLList.C->data.quantity << endl;
    } while (DLList.MoveNext());
    DLList.MoveFirst();
    return true;
}

void GetFlower(Flower& Info)
{
    cout << "enter flower's color:";
    cin >> Info.color;
    cout << endl;
    cout << "enter flower's cost:";
    cin >> Info.cost;
    cout << endl;
    cout << "enter flower's kind:";
    cin >> Info.kind;
    cout << endl;
    cout << "enter quantity:";
    cin >> Info.quantity;
    cout << endl;
}

int main()
{
    Flower Info;
    DLList DLList;
    GetFile(DLList, Info);
    DLList.Out();
    int num, count1 = 0, count2 = 0, count3 = 0;
    do
    {
        cout << "1) Add" << endl
            << "2) Del" << endl
            << "3) Clear" << endl
            << "4) Save changes" << endl
            << "0) Exit" << endl;
        cout << endl << "Select an action: ";
        cin >> count1;
        cout << endl;
        switch (count1)
        {
        case 1:
            cout << "1) Add to start" << endl
                << "2) Add to end" << endl
                << "3) Add to chosen position" << endl
                << "0) Back" << endl;
            cout << endl << "Select an action: ";
            cin >> count2;
            cout << endl;
            switch (count2)
            {
            case 1:
                GetFlower(Info);
                DLList.AddFirst(Info);
                DLList.Out();
                break;
            case 2:
                GetFlower(Info);
                DLList.AddLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Enter position: ";
                cin >> num;
                GetFlower(Info);
                if (num == 1)
                {
                    DLList.AddFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count + 1)
                {
                    DLList.AddLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num - 1; i++)
                {
                    DLList.MoveNext();
                }
                DLList.AddNext(Info);
                DLList.Out();
                break;
            default:
                if (count2 != 0)
                {
                    cout << "no such action!" << endl << endl;
                }
                break;
            }
            break;
        case 2:
            cout << "1. Delete first" << endl
                << "2. Delete last" << endl
                << "3. Delete chosen position" << endl
                << "0. Back" << endl;
            cout << endl << "Select an action: ";
            cin >> count3;
            cout << endl;
            switch (count3)
            {
            case 1:
                DLList.DelFirst(Info);
                DLList.Out();
                break;
            case 2:
                DLList.DelLast(Info);
                DLList.Out();
                break;
            case 3:
                cout << "Enter position: ";
                cin >> num;
                if (num == 1)
                {
                    DLList.DelFirst(Info);
                    DLList.Out();
                    break;
                }
                else if (num == DLList.Count)
                {
                    DLList.DelLast(Info);
                    DLList.Out();
                    break;
                }
                DLList.MoveFirst();
                for (int i = 1; i < num; i++)
                {
                    DLList.MoveNext();
                }
                DLList.Del(Info);
                DLList.Out();
                break;
            default:
                if (count3 != 0)
                {
                    cout << "action does not exist" << endl << endl;
                }
                break;
            }
            break;
        case 3:
            DLList.Clear();
            break;
        case 4:
            WriteFile(DLList, Info);
            break;
        default:
            if (count1 != 0)
            {
                cout << "action does not exist" << endl << endl;
            }
            DLList.Clear();
            DLList.Out();
            break;
        }
    } while (count1 != 0);
}
