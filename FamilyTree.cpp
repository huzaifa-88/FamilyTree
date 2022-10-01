#include <iostream>
#include <conio.h>
#include <queue>
#include <stack>
using namespace std;

//...........Prototypes
int mainMenu();
int subMenuDFS();
void clearScreen();
//...........Structure
struct TreeNode
{
    string name;
    int age;
    char gender;
    string parent;
    TreeNode *left;
    TreeNode *right;
};

// .............Class 
class familyTree
{
    TreeNode *root=NULL;
    queue<TreeNode *> Q;
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;

public:
    TreeNode *input(string name, int age, char gender)
    {
        TreeNode *temp = new TreeNode();
        temp->name = name;
        temp->age = age;
        temp->gender = gender;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    //................. Add family member in familyTree

    void addPerson()
    {
        string name;
        int age;
        char gender;
        cout << "Enter member name:";
        cin >> name;
        cout << "Enter member age:";
        cin >> age;
        cout << "Enter member gender:";
        cin >> gender;
        if (root == NULL)
            root = input(name, age, gender);
        else
        {
            if (age < root->age)
                root->left = input(name, age, gender);
            else if (age > root->age)
                root->right = input(name, age, gender);
        }
    }
    //................. Search any person

    void searchPerson(string name)
    {
        Q.push(root);
        while(!Q.empty())
        {
            if (root == nullptr || (root->left == NULL || root->right == NULL))
            {
                break;
            }
            TreeNode *temp = Q.front();
            Q.pop();
            if(temp->name==name)
            {
                cout << "Person Found!" << endl;
                cout << temp->name << " " << temp->age << " " << temp->gender << endl;
                break;
            }
            if(temp->left==nullptr)
            {
                Q.push(temp->left);
            }
            if(temp->right==nullptr)
            {
                Q.push(temp->right);
            }
        }
        cout << "Person is not Found!" << endl;
    }
    //................. view Parent using children name

    void viewParent(string name)
    {
        TreeNode *temp1;
        int count = 0;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();
            if(temp->name==name)
            {
                break;
            }
            else
            {
                temp1 = temp;
            }
            count++;
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
        if(count==0)
            cout << "Parent not Found!";
        else if(count > 0)
            cout << temp1->name << temp1->age << temp1->gender << endl;
    }
    //................. view Children using parent name

    void viewChildren(string name)
    {
        TreeNode *temp1;
        TreeNode *temp;
        int count = 0;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();
            if(temp->name==name)
            {
                break;
            }
            else
            {
                temp1 = temp;
            }
            count++;
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
        if(count==0)
            cout << "Parent not Found!";
        else if(count > 0)                             //Print Parent and their children
        {
            cout<<"Parent"<<endl;
            cout << temp1->name << temp1->age << temp1->gender << endl;
            if(temp->left!=NULL)
                cout << "1st Child" << endl;
                cout << temp->left->name << temp->left->age << temp->left->gender << endl;
            if(temp->right!=NULL)
                cout << "2nd Child" << endl;
                cout << temp->right->name << temp->right->age << temp->right->gender << endl;
            if(temp->left==NULL && temp->right==NULL)
                cout << "He has no child" << endl;
        }
    }
    //................. view familyInBFS

    void familyInBFS()
    {
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode *temp = Q.front();
            Q.pop();
            cout << temp->name << " " << temp->age << " " << temp->gender << endl;
            if(temp->left)
                Q.push(temp->left);
            if(temp->right)
                Q.push(temp->right);
        }
    }
    //................. view familyInDFS
    void preOrderView()
    {
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *temp = s1.top();
            s1.pop();
            cout << temp->name << " " << temp->age << " " << temp->gender << endl;
            if (temp->right)
                s1.push(temp->right);
            if (temp->left)
                s1.push(temp->left);
        }
    }
    void inOrderView()
    {
        TreeNode *temp = root;
        while (!s1.empty() || temp != nullptr)
        {
            if(temp!=NULL)
            {
                s1.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = s1.top();
                s1.pop();
                cout << temp->name << " " << temp->age << " " << temp->gender << endl;
                temp = temp->right;
            }
        }
    }
    void postOrderView()
    {
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *curr = s1.top();
            s2.push(curr);
            s1.pop();
            if (curr->left != NULL)
                s1.push(curr->left);
            if (curr->right != NULL)
                s1.push(curr->right);
        }
        while (!s2.empty())
        {
            TreeNode *temp = s2.top();
            s2.pop();
            cout << temp->name << " " << temp->age << " " << temp->gender << endl;
        }
    }
};
// ..........Main Start
main()
{
    familyTree family;
    int op;
    while (true)
    {
        op = mainMenu();
        if (op == 1)
        {
            family.addPerson();
            clearScreen();
        }
        else if (op == 2)
        {
            family.searchPerson("Dada");
            clearScreen();
        }
        else if (op == 3)
        {
            family.viewParent("Abbu");
            clearScreen();
        }
        else if (op == 4)
        {
            family.viewChildren("Dada");
            clearScreen();
        }
        else if (op == 5)
        {
            family.familyInBFS();
            clearScreen();
        }
        else if (op == 6)
        {
            int option = subMenuDFS();
            if(option==1)
            {
                family.preOrderView();
            }
            else if(option==2)
            {
                family.inOrderView();
            }
            else if(option==3)
            {
                family.postOrderView();
            }
            else
            {
                cout << "Wrong Input!";
            }
            clearScreen();
        }
        else if (op == 7)
        {
            break;
        }
        else
        {
            cout << "Invalid Input!" << endl;
        }
    }
}

// ............Functions Implementations
int mainMenu()
{
    int op;
    cout << "1-Add a person" << endl;
    cout << "2-View a person" << endl;
    cout << "3-Find parent of person" << endl;
    cout << "4-Find children of person" << endl;
    cout << "5-View Family in Breadth first traversal" << endl;
    cout << "6-View Family in Depth first traversal" << endl;
    cout << "7-Exit" << endl;
    cout << "Enter option:" << endl;
    cin >> op;
    return op;
}
int subMenuDFS()
{
    int op;
    cout << "View In Pre-Order";
    cout << "View in In-Order" << endl;
    cout << "View in Post-Order" << endl;
    cout << "Your Choice:";
    cin >> op;
    return op;
}
void clearScreen()
{
    cout << "Press any key to continue!" << endl;
    getch();
    system("cls");
}
