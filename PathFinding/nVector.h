#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template<class T>
class elem {
public:
    elem () { ; }
    elem (T nval) : val (nval) {  next = NULL; prev = NULL; }
    elem (T nval, elem* nprev) : val (nval) { next = NULL; prev = nprev; }

    elem<T> * gNext () { return next; }
    elem<T> * gprev () { return prev; }
    T& getVal () { return val; }

    void sNext (elem<T> * nnext) { next = nnext; }
    void sPrev (elem<T> * nprev) { prev = nprev; }

private:
    T val;
    elem<T> * next;
    elem<T> * prev;
};

template<class T>
class nVector {
public:
    nVector () {
        first = NULL;
        curr = NULL;
        init = false;
        VectorSize = 0;
    }

    void push_back (T val) {
        if (init) {
            setCurrLast ();
            elem<T> * n = new elem<T> (val, curr);
            curr->sNext (n);
            n->sPrev (curr);
            VectorSize++;
        }
        else {
            init = true;
            first = new elem<T> (val);
            VectorSize = 1;
        }
    }

    void push_first (T val) {
        if (init) {
            curr = first;
            elem<T> * n = new elem<T> (val);
            curr->sPrev (n);
            n->sNext (curr);
            first = n;
            VectorSize++;
        }
        else {
            init = true;
            first = new elem<T> (val);
            VectorSize = 1;
        }
    }

    bool erase (int index) {
        bool worked = true;

        if (init) {
            if (index > 0 && index < VectorSize) {
                if (setCurrIndex (index)) {
                    elem<T>* p = curr->gprev ();
                    if (p != NULL)
                        p->sNext (curr->gNext ());

                    elem<T>* n = curr->gNext ();
                    if (n != NULL)
                        n->sPrev (p);

                    delete curr;

                    VectorSize--;
                    if (VectorSize <= 0) {
                        init = false;
                    }
                }
            }
            else if (index == 0 && index < VectorSize) {
                elem<T> * n = first->gNext ();

                if (n != NULL) {
                    n->sPrev (NULL);
                    delete first;
                    first = n;
                    VectorSize--;
                }
                else {
                    init = false;
                    delete first;
                    VectorSize = 0;
                }
            }
            else {
                worked = false;
            }
        }
        else {
            worked = false;
        }
        return worked;
    }

    void concatenate (nVector<T>& t) {
        for (int i = 0; i < t.size (); ++i)
            push_back (t[i]);
    }

    int size () { return VectorSize; }
    bool empty () { return !init; }

    T& operator[](int ind) {
        setCurrIndex (ind);
        return curr->getVal ();
    }

    void show () {
        for (int i = 0; i < VectorSize; ++i) {
            setCurrIndex (i);
            std::cout << "(" << curr << ") Element " << i + 1 << " pere : " << curr->gprev() << ", fils " << curr->gNext () << std::endl;
        }
    }
private:
    void setCurrLast () {
        if (init) {
            curr = first;
            while (curr->gNext () != NULL) {
                curr = curr->gNext ();
            }
        }
    }

    bool setCurrIndex (int index) {
        curr = first;
        bool worked = true;

        for (int i = 0; i < index; ++i) {
            if (curr->gNext () != NULL)
                curr = curr->gNext ();
            else {
                worked = false;
                break;
            }
        }
        return worked;
    }

    elem<T>* first;
    elem<T>* curr;

    bool init;
    int VectorSize;
};
#endif
