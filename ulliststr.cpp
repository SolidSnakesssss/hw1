#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::push_back(const std::string& val)//Create new list
{
  if (empty())
  {
    head_ = new Item();

    head_->next = nullptr;
    head_->prev = nullptr;
    tail_=head_;

    head_->val[0] = val;
    size_++;

    head_->last++;
    
    return;
  }

  else if(tail_->last == ARRSIZE)
  {
    Item* temp = new Item();

    temp->prev = tail_;
    tail_->next = temp;
    temp->next = NULL;
    
    temp->first = 0;
    temp->last = 0;
    
    temp->val[temp->last] = val;
    temp->last++;

    tail_ = temp;

    size_++;
    return;
  }

  else
  {
    tail_->val[tail_->last] = val;
    tail_->last++;

    size_++;
  }
}

void ULListStr::pop_back()
{
  if(empty()) return;

  else if(headEqualsTails())
  {
    if(size_ == 1)
    {
      clear();

      return;
    }

    else
    {
      if(tail_->last == ARRSIZE)
      {
         tail_->val[tail_->last - 1] = '\0';
      }
      else
      {
        tail_->val[tail_->last] = '\0';
      }

      tail_->last--;
    }
  }

  else if(tail_->last == tail_->first)
    {
      Item* temp = tail_->prev;
      delete tail_;

      tail_ = temp;
      tail_->next = NULL;
    }

  else
    {
      tail_->val[tail_->last-1] = '\0';
      tail_->last--;
    }

   //std::cout <<"Hi Low" << std::endl;

  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if (empty())
  {
    head_ = new Item();

    head_->next = nullptr;
    head_->prev = nullptr;
    tail_=head_;

    tail_->last++;

    head_->val[0] = val;
    size_++;

    firstIndexReached = true;
    
    return;
  }

  else if(firstIndexReached == true)
  {
    Item* temp = new Item();

    temp->next = head_;
    head_->prev = temp;
    temp->prev = NULL;
    
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    
    temp->val[temp->first] = val;

    head_ = temp;

    size_++;
    firstIndexReached = false;
    return;
  }

  else
  {
    head_->first--;

    head_->val[head_->first] = val;

    if(head_->first == 0)
    {
      firstIndexReached = true;
    }

    size_++;
  }
}

void ULListStr::pop_front()
{
  if(empty()) return;

  else if(headEqualsTails())
  {
    if(size_ == 1)
    {
      clear();

      return;
    }

    else
    {
      head_->val[head_->first] = '\0';
      head_->first++;
    }
  }

  else if(head_->first == (ARRSIZE -1))
    {
      Item* temp = head_->next;
      delete head_;

      head_ = temp;
      head_->prev = NULL;
    }

  else
    {
      head_->val[head_->first] = '\0';
      head_->first++;
    }

  size_--;
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_)
  {
    return NULL;
  }

  Item* temp = head_;
  size_t currentIndex = temp->first;

  //std::cout << "Gorp " << temp->val[temp->first] << std::endl;

  for(size_t i = 0; i < loc; i++)
  {
    currentIndex++;

    if (currentIndex == ARRSIZE)
    {
      currentIndex = 0;
      temp = temp->next;
    }
  }

  //std::cout << "Steve: " << currentIndex << std::endl;
  //std::cout << temp->val[currentIndex] << std::endl;
  return &temp->val[currentIndex];
}

bool ULListStr::headEqualsTails() const
{
  return head_ == tail_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}