#ifndef MYDISJOINTSET_HPP
#define MYDISJOINTSET_HPP

#include <iostream>
#include <vector>

using namespace std;

class myDisjointSet
{
  public:
    explicit myDisjointSet(int numElements) : s(numElements, -1) { }

    int find(int x) const
    {
      if(s[x] < 0)
        return x;
      else
        return find(s[x]);
    }
    int find(int x)
    {
      if(s[x] < 0)
        return x;
      else
        return s[x] = find(s[x]);
    }
    void unionSets(int root1, int root2)
    {
      if(root1 == root2)
        return; // They are in teh same disjoint set, so no operations needed

      int size1 = getSetSize(root1);
      int size2 = getSetSize(root2);
      int updatedSize = s[root1] + s[root2];

      if(size1 < size2)
      {
        s[root1] = root2;
        s[root2] = updatedSize;
      }
      else
      {
        s[root2] = root1;
        s[root1] = updatedSize;
      }
    }

    void print(int i)
    {
      std::cout << i << std::endl;
      if(s[i] >= 0)
      {
        print(s[i]);
      }
    }
    int getNumberElements() const
    {
      return s.size();
    }
    int getSetSize(int i) const
    {
      return s[find(i)] * (-1);
    }

  private:
    std::vector<int> s;
};

#endif
