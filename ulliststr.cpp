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

void ULListStr::push_back(const std::string& val)
{
  if(head_ == NULL){
    head_ = new Item();
    head_->first = 0;
    head_->last = 0;
    head_->prev = NULL;
    head_->next = NULL;
    head_->val[0] = val;
    tail_ = head_;
  }
  else if(tail_->last < ARRSIZE - 1){
    tail_->last++;
    tail_->val[tail_->last] = val;
  }
  else{
    Item *temp = new Item();
    temp->first = 0;
    temp->last = 0;
    temp->prev = tail_;
    temp->next = NULL;
    temp->val[0] = val;
    tail_->next = temp;
    tail_ = temp;
  }
}

void ULListStr::pop_back()
{
  if(head_ == NULL){
    return;
  }
  else if(head_ == tail_){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else if(tail_->last == 0){
    Item *temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = NULL;
  }
  else{
    tail_->last--;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL){
    head_ = new Item();
    head_->first = 0;
    head_->last = 0;
    head_->prev = NULL;
    head_->next = NULL;
    head_->val[0] = val;
    tail_ = head_;
  }
  else if(head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;
  }
  else{
    Item *temp = new Item();
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE - 1;
    temp->prev = NULL;
    temp->next = head_;
    temp->val[ARRSIZE - 1] = val;
    head_->prev = temp;
    head_ = temp;
  }
}

void ULListStr::pop_front()
{
  if(head_ == NULL){
    return;
  }
  else if(head_ == tail_){
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else if(head_->first == ARRSIZE - 1){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
    head_->prev = NULL;
  }
  else{
    head_->first++;
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return NULL;
  }

  Item *temp = head_;

  size_t shortcut = size_ - loc - 1;

  if(shortcut >= size_ / 2)
  {
    temp = tail_;
    size_t indexTracker = size_ - 1;

    while (indexTracker != loc)
    {
      temp = temp->prev;
    }

    return &(temp->val[loc % ARRSIZE]);
  }

  else
  {
    size_t indexTracker = 0;

    while (indexTracker != loc)
    {
      temp = temp->next;
    }

    return &(temp->val[loc % ARRSIZE]);
  }
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