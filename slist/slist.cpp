#include "slist.h"
#include <cmath>
slist::slist(comparator c) : first(nullptr), count(0), c(c)
{
}
slist::~slist()
{
    clear();
}
void slist::clear()
{
    slist::skipBox *crr = first, *save;
    while (crr != nullptr)
    {
        save = crr;
        crr = crr->next;
        delete save;
    }
}
slist::skipBox::skipBox(const int &data, skipBox *next, skipBox *skip) : data(data), next(next), skip(skip)
{
}
size_t slist::size() const
{
    return count;
}
bool slist::member(const int &_data) const
{
    if (first == nullptr)
    {
        return false;
    }
    slist::skipBox *crr = first;
    while (crr->skip != nullptr && c(crr->skip->data, _data))
    {
        crr = crr->skip;
    }
    while (crr != nullptr && crr->data != _data)
    {
        crr = crr->next;
    }
    return crr != nullptr;
}
typename slist::skipBox *slist::locate(const int &data) const
{
    if (first == nullptr || !c(first->data, data))
    {
        return nullptr;
    }
    slist::skipBox *crr = first;
    while (crr->next != nullptr && c(crr->next->data, data))
    {
        crr = crr->next;
    }
    return crr;
}
void slist::skipping()
{
    slist::skipBox *crr = first, *lastCrr = first;
    size_t br = 0;

    while (crr != nullptr)
    {
        crr = crr->next;
        ++br;
        if (br >= sqrt(size()))
        {
            lastCrr->skip = crr;
            lastCrr = crr;
            br = 0;
        }
    }
}
void slist::pushSorted(const int &data)
{
    
  count++;

  slist::skipBox *el = locate(data);

  if (el == nullptr)
  {
      first = new slist::skipBox (data, first, nullptr);
      return;     
  }
  
  el->next = new slist::skipBox (data, el->next,nullptr);
  skipping();
}

std::ostream &operator<<(std::ostream &out, const slist &list)
{

    typename slist::skipBox *current = list.first;
    while (current != nullptr)
    {
        out << current->data << " ";
        current = current->next;
    }
    return out;
}
