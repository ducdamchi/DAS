#pragma once

/**
 * The PriorityQueue is a pure virtual (abstract) interface representing a
 * priority queue.  Clients may request the next element via the take() method;
 * the definition of "next" is dependent upon implementation.
 * @tparam P The type of priorities of queue elements.
 * @tparam V The type of the queue elements themselves.
 */
template <typename P, typename V> class PriorityQueue {
  public:
    virtual ~PriorityQueue(){};

    /**
     * Adds an item with given priority and value to this priority queue.  The
     * meaning of this priority is dependent upon the implementation.
     * @param priority The priority of the item being added.
     * @param value The value to store in the queue at that priority.
     */
    virtual void insert(P priority, V value) = 0;

    /**
     * Removes the next item from this priority queue and returns its value.
     * The "next" item is based upon the priority with which it was added to the
     * queue; the meaning of that priority is left up to the implementation.
     * @return The value of the removed item.
     * @throws runtime_error if there are no items in the priority queue.
     */
    virtual V remove() = 0;

    /**
     * Retrieves the next item from this queue (without removing it).
     * @return The value of the next item.
     * @throws runtime_error If there are no items in the priority queue.
     */
    virtual V peek() = 0;

    /**
     * Retrieves the priority of the next item in the queue.
     * @return The priority of the next item in the queue.
     * @throws runtime_error if there are no items in the priority queue.
     */
    virtual P peekPriority() = 0;

    /**
     * Determines the number of elements in the priority queue.
     * @return The number of elements in the priority queue.
     */
    virtual int getSize() = 0;

    /**
     * Determines whether this priority queue is empty.
     * @return true if the priority
     */
    virtual bool isEmpty() = 0;

  public:
    PriorityQueue() {
    }

  private:
    PriorityQueue(const PriorityQueue& other) = delete;
    PriorityQueue& operator=(const PriorityQueue& other) = delete;
};
