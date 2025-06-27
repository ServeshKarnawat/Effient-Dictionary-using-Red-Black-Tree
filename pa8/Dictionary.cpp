//Servesh Karnawat
//skarnawa
//pa8

#include<iostream>
#include<string>
#include "Dictionary.h"


// Exported types -------------------------------------------------------------
typedef std::string keyType;  // must be comparable using <, <=, >, >=, ==, !=
typedef int valType;





   // private Node struct
Dictionary::Node::Node(keyType k, valType v){
    // Node fields
    key = k;
    val = v;
    color = BLACK;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}
Dictionary::Dictionary(){

   // Dictionary fields
   nil= new Node("", 0);
   root = nil;
   current = nil;
   num_pairs = 0;


   nil->parent = nil;
   nil->left = nil;
   nil->right = nil;
}
Dictionary::Dictionary(const Dictionary& D){
    nil = new Node("",0);
    root = nil;
    current = nil;
    num_pairs = 0;
    
    nil->parent= nil;
    nil->left = nil;
    nil->right= nil;

    preOrderCopy(D.root,D.nil);
}

// Destructor
Dictionary::~Dictionary(){
    postOrderDelete(root);
    num_pairs = 0;
    delete nil;
}

   // Helper Functions (Optional) ---------------------------------------------
// RBT Helper Functions (Optional) -----------------------------------------


//Got these from PTantalo Psuedocode examples

// LeftRotate()
void Dictionary::LeftRotate(Node* N){
    Node *x = N;
    Node *y = x->right;
    x->right = y->left;

    if(y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    
    if(x->parent == nil){
        root = y;
    }
    else if (x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;

}

// RightRotate()
void Dictionary::RightRotate(Node* N){
    Node *x = N;
    Node* y = x->left;

    x->left = y->right;
    if(y->right != nil){
        y->right->parent =x;
    }

    y->parent = x->parent;
    if(x->parent == nil){
        root = y;
    }
    else if(x == x->parent->right){
        x->parent->right = y;
    }
    else{
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

// RB_InsertFixUP()
void Dictionary::RB_InsertFixUp(Node* N){
    Node *y;
    Node *z = N;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
            y = z->parent->parent->right;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->right){
                    z= z->parent;
                    LeftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                RightRotate(z->parent->parent);
            }
        }
        else{
            y = z->parent->parent->left;
            if(y->color == RED){
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    RightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                LeftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;

}

// RB_Transplant()
void Dictionary::RB_Transplant(Node* u, Node* v){
    if(u->parent == nil){
        root = v;
    }
    else if( u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
   
    v->parent = u->parent;
    

}

// RB_DeleteFixUp()
void Dictionary::RB_DeleteFixUp(Node* N){
    Node *x = N;
    Node *w;
    while(x != root && x->color == BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                LeftRotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color== BLACK){
                w->color = RED;
                x = x->parent;
            }
            else{
                if(w->right->color == BLACK){
                    w->left->color = BLACK;
                    w->color= RED;
                    RightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color=BLACK;
                w->right->color = BLACK;
                LeftRotate(x->parent);
                x= root;
            }

        }
        else{
            w = x->parent->left;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                RightRotate(x->parent);
                w = x->parent->left;
            }
            if(w->right->color == BLACK && w->left->color == BLACK){
                w->color = RED;
                x = x->parent;
            }
            else{
                if(w->left->color == BLACK){
                    w->right->color = BLACK;
                    w->color = RED;
                    LeftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                RightRotate(x->parent);
                x=root;
            }

        }
        
    }
    x->color = BLACK;

}


// RB_Delete()
//void Dictionary::RB_Delete(Node* N){

//}


   // inOrderString()
   // Appends a string representation of the tree rooted at R to string s. The
   // string appended consists of: "key : value \n" for each key-value pair in
   // tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const{
    if(R != nil && R!= nullptr){
        inOrderString(s, R->left);
        s +=(R->key );
        s+= " : "; 
        s+= std::to_string(R->val);
        s+= "\n";
        inOrderString(s, R->right);
    }


}

// preOrderString()
// Appends a string representation of the tree rooted at R to s. The appended
// string consists of keys only, separated by "\n", with the order determined
// by a pre-order tree walk.
void Dictionary::preOrderString(std::string& s, Node* R) const{
    if(R != nil){
        s += R->key;
        if(R->color == RED){
            s+= " (RED)";
        }
        s += "\n";
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }

}

   // preOrderCopy()
   // Recursively inserts a deep copy of the subtree rooted at R into this 
   // Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N){
    //root nil
    if(R != N){
        setValue(R->key,R->val);
        preOrderCopy(R->left,N);
        preOrderCopy(R->right,N);
    }

}

   // postOrderDelete()
   // Deletes all Nodes in the subtree rooted at R.
void Dictionary::postOrderDelete(Node* R){
    if(R != nil){
        if(R->left != nil){
            postOrderDelete(R->left);
        }
        if(R->right != nil){
            postOrderDelete(R->right);
        }
        
        delete R;
    }
}



// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R){
    if(R->left == nil){
        return R;
    }
    else{
        return findMin(R->left);
    }
    //adding a random return that will never execute to get the
    //terminal errors to shut up
    
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R){
    if(R->right == nil){
        return R;
    }
    else{
        return findMax(R->right);
    }
    //adding a random return that will never execute to get the
    //terminal errors to shut up
    
}

// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N){
    if(N == nil){
        return nil;
    }
    //Node *og = N;
    //if(N->right != nil){
    //    return (findMin((current->right)));
    //}
    if(N->left == nil &&N->right == nil && N->parent->left == N){
        return N->parent;
    }
    else if(N->left == nil &&N->right == nil && N->parent->right == N){
        return nil;
    }
    else{
        N = N->right;
        if(N->left != nil){
            return findMin(N);
        }
        else{
            return N;

        }
    }
    /*
    Node* parentN = N->parent;
    while(parentN != nil && N == parentN->right){
        N= parentN;
        parentN = parentN->parent;
    }
    if(parentN->key > og->key){
        return parentN;
    }
    else{
        return nil;
    }
    */
    /*
    if(N->right== nil){
        return nil;
    }
    else{
        return(findNext(N->right));
    }
    //adding a random return that will never execute to get the
    //terminal errors to shut up
    return N;
    */

}

// findPrev()
// If N does not point to the leftmost Node, returns a pointer to the
// Node before N in an in-order tree walk.  If N points to the leftmost 
// Node, or is nil, returns nil.
Dictionary::Node* Dictionary::findPrev(Node* N){
    if(N == nil){
        return nil;
    }
    if(N->left == nil&& N->parent == nil){
        return nil;
    }
    if(findMin(root) == N){
        return nil;
    }
    if(N->left != nil){
        return findMax(N->left);
    }
    if(N->left ==nil && N->right == nil && N->parent->right == N){
        return N->parent;
    }
    if(N->left== nil){
        if(N->right != nil && N->parent != nil){
            return N->parent;
        }
        if(N->parent->left == N){
            while(N->parent->right !=nil && N->parent->parent != nil){
                N = N->parent;
            }
            return N->parent;

        }
        else{
            return N;

        }
    }
    else{
            return N;

        }




    /* 
    if(N->left == nil&& N->parent == nil){
        return nil;
    }
    if(N->left == nil &&N->right == nil){
        return N->parent;
    }
    
    Node *og = N;
    if(N->left != nil){
        return (findMax((current->left)));
    }
    Node* parentN = N->parent;
    while(parentN != nil && N == parentN->left){
        N= parentN;
        parentN = parentN->parent;
    }
    if(parentN->key < og->key){
        return parentN;
    }
    else{
        return nil;
    }
    */


    /*
    if(N->left== nil){
        return nil;
    }
    else{
        return(findPrev(N->left));
    }
    */

}


// Class Constructors & Destructors ----------------------------------------

// Creates new Dictionary in the empty state. 


// Copy constructor.


// Access functions --------------------------------------------------------

// size()
// Returns the size of this Dictionary.
int Dictionary::size() const{
    return num_pairs;
}

// contains()
// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const{
    if(root == nil){
        return false;
    }

    if(search(root, k) != nil){
        return true;
    }
    else{
        return false;
    }
}

// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const{
    if(!contains(k)){
        throw std::logic_error("getvalue called on key that doesn't exist\n");
    }
    return (search(root, k))->val;
}

// hasCurrent()
// Returns true if the current iterator is defined, and returns false 
// otherwise.
bool Dictionary::hasCurrent() const{
    if (current == nil){
        return false;
    }
    else{
        return true;
    }
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent() 
keyType Dictionary::currentKey() const{
    if(hasCurrent()){
        return current->key;
    }
    else{
        throw std::logic_error("currentKey called where current doesnt have key\n");
    }
}

// currentVal()
// Returns a reference to the current value.
// Pre: hasCurrent()
valType& Dictionary::currentVal() const{
    if(!hasCurrent()){
       
        throw std::logic_error("currentval called where current doesnt have key\n");

    }
    else{

    return current->val;
    }
}


// Manipulation procedures -------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear(){
    postOrderDelete(root);
    root = nil;
    current = nil;
    num_pairs = 0;
}
   // search()
// Searches the subtree rooted at R for a Node with key==k. Returns
// the address of the Node if it exists, returns nil otherwise.
Dictionary::Node* Dictionary::search(Node* R, keyType k) const{
    if(R == nil || R== nullptr){

        return nil;
    }
    if(R->key == k ){
        return R;
    }
    if(k < R->key ){
        return search(R->left,k);
        
    }
    else{
        return search(R->right,k);
        
    }
    //adding a random return that will never execute to get the
    //terminal errors to shut up
    
}
// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v, 
// otherwise inserts the new pair (k, v).
void Dictionary::setValue(keyType k, valType v){
    
    Node *ins = new Node(k, v);
    Node *found = search(root, k);
    if(found != nil){
        
        found->val = v;
        delete ins;
        return;
        
    }

    else{
        
        num_pairs++;
        Node *y = nil;
        Node *x = root;
        while(x != nil){
            y = x;
            if(ins->key < x->key){
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }
        ins->parent = y;
        if( y == nil)
        {
            root = ins;
        }
        else if (ins->key < y->key)
        {
            y->left = ins;
        }
        else
        {
            y->right = ins;
        }
        ins->left = nil;
        ins->right = nil;
        ins->color = RED;
        RB_InsertFixUp(ins);
        





        /*
        num_pairs++;
        
        if(root == nil){
            
            root = ins;
            root->left = nil;
            root->right = nil;
            root->parent = nil;
            
            
        }
        else{
            Node *y = nil;
            Node *x = root;
            while (x != nil){
                y= x;
                if(ins->key < x->key){
                    x = x->left;
                }
                else{
                    x= x->right;
                }
            }
            ins->parent = y;
            ins->left = nil;
            ins->right = nil;
            if (y == nil){
                root = ins;
               
            }
            else if(ins->key < y->key){

                y->left = ins;
                
            }
            else{
                y->right = ins;
                
            }
            
            ins->left = nil;
            ins->right = nil;
            ins->color = RED;
            RB_InsertFixUp(ins);
            
        }*/

    }
}



void Dictionary::remove(keyType k){
    
    
    if(!contains(k)){
        throw std::logic_error("remove called on nonexistant key");
    }
    
    Node *z = search(root, k);
    Node *y = z;
    Node *x;
    if(z == current){
        current = nil;
    }
    num_pairs--;
    int yOgColor = y->color;
    if(z->left == nil){
        x = z->right;
        RB_Transplant(z, z->right);
    } 
    else if(z->right == nil){
        x = z->left;
        RB_Transplant(z, z->left);
    }
    else{
        y = findMin(z->right);
        yOgColor = y->color;
        x = y->right;
        if( y->parent == z){
            x->parent = y;
        }
        else{
            RB_Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        RB_Transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;

    }
    if(yOgColor == BLACK){
        RB_DeleteFixUp(x);
    }
    if(z!= nullptr){
        delete z;
        z= nullptr;
    }
    
    
}


/*
// remove()
// Deletes the pair for which key==k. If that pair is current, then current
// becomes undefined.
// Pre: contains(k).
void Dictionary::remove(keyType k){

    if(!contains(k)){
        throw std::logic_error("remove called where current doesnt have key\n");
    }

    
    Node *rem = search(root,k);
    if(current == rem ){
        current = nil;
    }
    if(num_pairs == 1){
        clear();
        return;
    }
    Node *replacement ;
    num_pairs--;
    if(rem->right == nil && rem->left==nil){
        rem->left = nullptr;
        rem->right = nullptr;
        if(rem->parent->left == rem){
            rem->parent->left = nil;
        }
        if(rem->parent->right == rem){
            rem->parent->right = nil;
        }
        delete rem;


    }
    else{
        if(rem->right!=nil){
            replacement = findMin(rem->right);
        }
        else if(rem->right== nil && rem->left != nil){
            replacement = findMin(rem);
        }
        else{
            Node *y = rem->parent;
            while(y!=nil && rem == y->right){
                rem = y;
                y = y->parent;
            }
            replacement = y;
        }

        rem->key = replacement->key;
        rem->val = replacement->val;

        replacement->left = nullptr;
        replacement->right = nullptr;
        if(replacement->parent->left == replacement){
            replacement->parent->left = nil;
        }
        if(replacement->parent->right == replacement){
            replacement->parent->right = nil;
        }
        delete replacement;
    }
}
    
*/
    //


    /*
    //if there is two children
    Node *found = search(root,k);
    Node *replace;
    if(found->left != nil && found->right != nil){
        replace = found->right;
        replace= findMin(replace);
        found->key = replace->key;
        found->val = replace->val;

        replace->left= nullptr;
        replace->right= nullptr;
        if(replace->parent->left = replace){
            replace->parent->left= nil;
        }
        if(replace->parent->right = replace){
            replace->parent->right= nil;
        }
        delete replace;

        */
        /*
        delete replace->left;


        delete replace->right;
        replace= nil;
        
        //if i delete this instead then if I try to find the 
        //left of the one before this then it will see null and freak
        //out right or will it cause memory leak
        //possile memory leak
        //delete replace->left;
        
    }

    //if there is one child

    //left has something 
    else if(found->left!= nil){
        replace = found->left;
        found = replace;
        if(replace->left== nil && replace->right==nil){
            delete replace->left;
            delete replace->right;
            replace= nil;

        }
        //maybe leak source?
    }
    else if(found->right!= nil){
        replace = found->right;
        found = replace;
        if(replace->left== nil && replace->right==nil){
            delete replace->left;
            delete replace->right;
            replace= nil;

        }
        //maybe leak source?
    }
    

    //if there is no child
    else{
        delete found->left;
        delete found->right;
        found = nil;
    }



}
*/
// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::begin(){
    if(num_pairs > 0){
        Node *c = root;
        while(c->left != nil){
            c = c->left;

        }
        current = c;

    }
}

// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing. 
void Dictionary::end(){
    if(root != nil){
        Node *c = root;
        while(c->right != nil){
            c = c->right;

        }
        current = c;
    }

}

// next()
// If the current iterator is not at the last pair, advances current 
// to the next pair (as defined by the order operator < on keys). If 
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next(){
    if(hasCurrent()){
        current = findNext(current);
    }
    else{
        current = nil;
    }

}

// prev()
// If the current iterator is not at the first pair, moves current to  
// the previous pair (as defined by the order operator < on keys). If 
// the current iterator is at the first pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::prev(){
    if(hasCurrent()){
        current = findPrev(current);
    }
    else{
        current = nil;
    }

}


// Other Functions ---------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value 
// are separated by the sequence space-colon-space " : ". The pairs are arranged 
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const{
    std::string inOr;
    inOrderString(inOr, root);
    return inOr;
}

// pre_string()
// Returns a string consisting of all keys in this Dictionary. Consecutive
// keys are separated by newline "\n" characters. The key order is given
// by a pre-order tree walk.
std::string Dictionary::pre_string() const{
    std::string inOr;
    preOrderString(inOr, root);
    return inOr;
}

// equals()
// Returns true if and only if this Dictionary contains the same (key, value)
// pairs as Dictionary D.
bool Dictionary::equals(const Dictionary& D) const{
    return to_string() == D.to_string();
}


// Overloaded Operators ----------------------------------------------------

// operator<<()
// Inserts string representation of Dictionary D into stream, as defined by
// member function to_string().
std::ostream& operator<<( std::ostream& stream, Dictionary& D ){
    stream << D.to_string();
    return stream;

}

// operator==()
// Returns true if and only if Dictionary A equals Dictionary B, as defined
// by member function equals(). 
bool operator==( const Dictionary& A, const Dictionary& B ){
    return A.equals(B);
}

// operator=()
// Overwrites the state of this Dictionary with state of D, and returns a
// reference to this Dictionary.
Dictionary& Dictionary::operator=( const Dictionary& D ){
    clear();
    preOrderCopy(D.root,D.nil);
    return *this;
}


