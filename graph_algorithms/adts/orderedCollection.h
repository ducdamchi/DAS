#pragma once

/**
 * The OrderedCollection is a pure virtual (abstract) interface representing a
 * collection of elements which may be removed in some order.  The particular
 * implementation of the OrderedCollection dictates the order in which they are
 * removed.
 * @tparam T The type of elements stored in the queue.
 */
template <typename T> class OrderedCollection {
  public:
    virtual ~OrderedCollection(){};

    /**
     * Adds an element to the collection.
     * @param item The element to collection.
     */
    virtual void insert(T element) = 0;

    /**
     * Removes an element from the collection.
     * @return The element that was removed.
     * @throws runtime_error If the collection was empty.
     */
    virtual T remove() = 0;

    /**
     * Determines the size of this collection.
     * @return The number of elements in the collection.
     */
    virtual int getSize() = 0;

    /**
     * Determines whether this collection is empty.
     * @return true if the collection is empty; false if it is not.
     */
    virtual bool isEmpty() = 0;

    /**
     * Retrieves the next element from the collection (without removing it).
     * This is the same element which would be returned by the take() method.
     * @return The next element in the collection.
     * @throws runtime_error If the queue is empty.
     */
    virtual T peek() = 0;
    
  public:
    OrderedCollection() {
    }

  private:
    OrderedCollection(const OrderedCollection& other) = delete;
    OrderedCollection& operator=(const OrderedCollection& other) = delete;
};
