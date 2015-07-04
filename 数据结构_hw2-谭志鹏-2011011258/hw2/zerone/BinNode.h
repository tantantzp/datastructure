#ifndef BINNODE_H
#define BINNODE_H


class BinNode             //Ê÷Ö¦½ÚµãÀà 
{
public:
    int data;
    BinNode* parent,*lChild,*rChild;
    BinNode(int d,BinNode* p=NULL,BinNode* l=NULL,BinNode* r=NULL);
    BinNode* insertAsLC(int const& );
    BinNode* insertAsRC(int const& );
};

BinNode::BinNode(int d, BinNode *p, BinNode *l, BinNode *r)
{
    data=d;
    parent=p,lChild=l,rChild=r;
}


BinNode* BinNode::insertAsLC(const int &d)
{
    return lChild=new BinNode(d,this);
}

BinNode* BinNode::insertAsRC(const int &d)
{
    return rChild=new BinNode(d,this);
}



#endif // BINNODE_H
