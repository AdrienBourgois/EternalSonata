#ifndef __ITEM_H__
#define __ITEM_H__



class Item
{
    private:
        int test;

    public:
        Item() = default;
        Item(Item const&) = default;
        ~Item() = default;

        Item& operator =(Item const&) = default;

        int getTest(){return test;};
        void setTest(int x){test = x;};
};

#endif
