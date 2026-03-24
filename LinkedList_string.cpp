#include "LinkedList_string.h"

LinkedList::LinkedList():head(nullptr)
{

}

LinkedList::LinkedList(const LinkedList& other):head(nullptr)
{
	Node* temp = other.head;

	while(temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
}

LinkedList::~LinkedList()
{
	clear();
}

string& LinkedList::at(int index){
	Node* temp = head;
	int pos = 0;
	while(temp != nullptr && pos < index)
	{
		temp = temp->next;
		pos++;
	}
	return temp->data;
}

string& LinkedList::front(){
	return head->data;
}

string& LinkedList::back(){
	Node* temp = head;
	while(temp->next != nullptr)
	{
		temp = temp->next;
	}
	return temp->data;
}

void LinkedList::push_back(const string& value)
{
	Node* newNode = new Node(value);
	if(empty()) {head = newNode; return;}
	Node* temp = head;
	while(temp->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

void LinkedList::pop_back()
{
	if(empty()){return;}

	Node* temp = head;
	if(temp->next == nullptr)
	{	delete head;
		head = nullptr;
		return;
	}
	while(temp->next->next != nullptr)
	{
		temp = temp->next;
	}
	delete temp->next;
	temp->next = nullptr;
}

void LinkedList::push_front(const string& value)
{
	Node* firstnode = new Node(value);
	firstnode->next = head;
	head = firstnode;
}

void LinkedList::pop_front()
{
	if(empty()){return;}

	Node* tempToDelete = head;

	head = tempToDelete->next;

	delete tempToDelete;
	
}

void LinkedList::insert_at(int index, const string& value)
{
	Node* temp = head;
	Node* prev = nullptr;
	int pos = 0;
	if(index == 0){push_front(value); return;}
	while(temp != nullptr && pos < index)
	{
		prev = temp;
		temp = temp->next;
		pos++;
	}
	Node* newNode = new Node(value);
	prev->next = newNode;
	newNode->next = temp;
}

void LinkedList::insert_after(int index, const string& val)
{
	Node* temp = head;
	int pos = 0;

	while(temp != nullptr && pos < index)
	{
		temp = temp->next;
		pos++;
	}
	if(temp == nullptr){return;} // If enters bigger than list.
	Node* newNode = new Node(val);
	newNode->next = temp->next;
	temp->next = newNode;	
}

void LinkedList::erase_at(int index)
{
	if(empty()){return;}
	Node* temp = head;
	Node* prev = nullptr;
	int pos = 0;
	
	if(index == 0){pop_front(); return;}
	
	while(temp != nullptr && pos < index)
	{
		prev = temp;
		temp = temp->next;
		pos++;
	}
	if (temp == nullptr) {return;}
	prev->next = temp->next;
	delete temp;
}

void LinkedList::erase(const string& e)
{
	if(empty()){return;}
	if(head->data == e) {pop_front(); return;}

	Node* temp = head;
	Node* prev = nullptr;

	while(temp != nullptr && temp->data != e)
	{
		prev = temp;
		temp = temp->next;
	}
	if(temp == nullptr){return;}
	prev->next = temp->next;
	delete temp;
}

void LinkedList::clear()
{
	while(!empty())
	{
		pop_front();
	}
}

int LinkedList::size() const
{
	int count = 0;
	Node* temp = head;
	while(temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}

bool LinkedList::empty() const{
	return head==nullptr;
}

LinkedList& LinkedList::operator=(const LinkedList& lhs)
{
	if (this == &lhs) {return *this;} // kendisini silmemesi icin

	clear();

	Node* temp = lhs.head;
	while(temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}
	return *this;

}

bool LinkedList::operator==(const LinkedList& lhs) const
{
	Node* p1 = this->head;
	Node* p2 = lhs.head;

	while(p1 != nullptr && p2 != nullptr)
	{
		if(p1->data != p2->data){return false;}
		p1 = p1->next;
		p2 = p2->next;
	}
	if(p1 == nullptr && p2 == nullptr){return true;}
	return false;
}

ostream& operator<<(ostream& out, const LinkedList& list)
{
	Node* temp = list.head;
	
	while(temp != nullptr)
	{
		out << temp->data << "->";
		temp = temp->next;
	}
	out << "NULL";
    return out;
}

Node* LinkedList::findMiddleNode()
{
	if(head == nullptr){return nullptr;}

	Node* move1 = head; // birer birer gider.
	Node* move2 = head; // ikiser ikser gider.

	while(move1 != nullptr && move2 != nullptr)
	{
		move1 = move1->next;
		move2 = move2->next->next;
	}
	return move1;
}

Node* LinkedList::getSmallestNode()
{
	if(head == nullptr){return nullptr;}

	Node* smallest = head;
	Node* temp = head;

	while(temp != nullptr)
	{
		if(temp->data < smallest->data)
		{
			smallest = temp;
		}
		temp = temp->next;
	}
	return smallest;
}

void LinkedList::moveSmallestToFront()
{
	if(head == nullptr || head->next == nullptr){return;}

	Node* smallest = head;
	Node* prevSmallest = nullptr;
	Node* temp = head;
	Node* prev = nullptr;

	while(temp != nullptr)
	{
		if(temp->data < smallest->data)
		{
			smallest = temp;
			prevSmallest = prev;
		}
		prev = temp;
		temp = temp->next;
	}
	if(smallest == head) {return;}

	prevSmallest->next = smallest->next;
	smallest->next = head;
	head = smallest;
}