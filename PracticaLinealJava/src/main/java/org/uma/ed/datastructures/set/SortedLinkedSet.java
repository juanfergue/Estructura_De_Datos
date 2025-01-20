package org.uma.ed.datastructures.set;

import java.util.Comparator;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class SortedLinkedSet <T> extends AbstractSet <T> implements SortedSet<T>{
    private Node<T> first; // Referencia al primer nodo
    private Comparator<T> comparator; // Comparador para definir el orden de los elementos
    private int size;

    public SortedLinkedSet(Comparator<T> comparator) { //Contructor 1
        this.comparator = comparator;
        this.first = null;
        this.size = 0;
    }

    private static final class Node<E> {
        E element; // Elemento almacenado en el nodo
        Node<E> next; // Referencia al siguiente nodo
        Node(E element, Node<E> next) {
            this.element = element;
            this.next = next;
        }
    }

    private SortedLinkedSet(SortedLinkedSetBuilder<T> builder) { //Constructor 2
        this.first = builder.first;
        this.size = builder.size;
        this.comparator = builder.comparator;
    }


    private final class Finder {
        boolean found; // Indica si se encontró el elemento objetivo
        Node<T> previous, current; // Referencias a anterior y actual
        Finder(T element) { // El constructor toma el elemento objetivo
            previous = null;
            current = first;
            int cmp = 0;
            while (current != null && (cmp = comparator.compare(element,
                    current.element)) > 0) {
                previous = current;
                current = current.next;
            }
            found = current != null && cmp == 0;
        }
    }
    private final class SortedLinkedSetIterator implements Iterator<T> {
        Node<T> current;
        SortedLinkedSetIterator() {
            current = first;
        }
        @Override
        public boolean hasNext() {
            return current != null;
        }
        @Override
        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException("next on empty iterator");
            }
            T element = current.element;
            current = current.next;
            return element;
        }
    }
    private static final class SortedLinkedSetBuilder<T> {
        Node<T> first, last;
        int size;
        Comparator<T> comparator;
        SortedLinkedSetBuilder(Comparator<T> comparator) {
            this.first = null;
            this.last = null;
            this.size = 0;
            this.comparator = comparator;
        }
        void append(T element) {
            assert first == null || comparator.compare(element, last.element)
                    > 0;
            Node<T> node = new Node<>(element, null);
            if (first == null) { // el builder estaba vacío
                first = node;
            } else {
                last.next = node;
            }
            last = node;
            size++;
        }
        // convierte el builder en un SortedLinkedSet en tiempo O(1)
        SortedLinkedSet<T> toSortedLinkedSet() {
            return new SortedLinkedSet<>(this);
        }
    }

    public interface Set<T> extends Iterable<T> {
        void insert(T element);
        void delete(T element);
        boolean contains(T element);
        boolean isEmpty();
        int size();
        void clear();
    }
    public interface SortedSet<T> extends Set<T> {
        Comparator<T> comparator();
        T minimum();
        T maximum();
    }

    /**
     * Retrieves the comparator that defines the order of the elements in this SortedSet.
     *
     * @return The comparator used to order the elements in this SortedSet.
     */
    @Override
    public Comparator<T> comparator() {
        return comparator;
    }

    /**
     * Retrieves the smallest element in this set according to the set's ordering.
     *
     * @return The smallest element in this set.
     * @throws NoSuchElementException if the set is empty.
     */
    @Override
    public T minimum() {
        if(first == null){
            throw new NoSuchElementException("Cadena Vacia");
        }
        T minimo = null;

        minimo = first.element;

        return minimo;

    }

    /**
     * Retrieves the largest element in this set according to the set's ordering.
     *
     * @return The largest element in this set.
     * @throws NoSuchElementException if the set is empty.
     */
    @Override
    public T maximum() {
        if(first == null){
            throw new NoSuchElementException("Cadena Vacia");
        }
        Node<T> iter = first;
        T maximo = null;
        while(iter.element != null){
            maximo = iter.element;
            iter = iter.next;
        }
        return maximo;
    }

    /**
     * Checks if the set is empty.
     *
     * @return {@code true} if the set has no elements, {@code false} otherwise.
     */
    @Override
    public boolean isEmpty() {
        return first.element == null; // o con this.size == 0;
    }

    /**
     * Retrieves number of elements in the set (its cardinal).
     *
     * @return Number of elements in the set.
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Inserts a new element into the set. If the element already exists, the set remains unchanged.
     *
     * @param element The element to be inserted.
     */
    @Override
    public void insert(T element) {
        Finder encontrado = new Finder(element);
        if(!encontrado.found){
            Node<T> nuevo = new Node(element,null);
            if(encontrado.previous == null) { //es decir hay que meterlo en la primera posicion
                first = nuevo;
                nuevo.next = encontrado.current;
            }else if(encontrado.current == null){ //significa que el nuevo va al final
                encontrado.current = nuevo;
                encontrado.previous.next = nuevo;
            }else{
                encontrado.previous.next = nuevo;
                nuevo.next = encontrado.current;
            }
        }
    }

    /**
     * Checks if an element is present in the set.
     *
     * @param element The element to check for.
     * @return {@code true} if the element is in the set, {@code false} otherwise.
     */
    @Override
    public boolean contains(T element) {
        Finder encontrado = new Finder(element);
        return encontrado.found;
    }

    /**
     * Removes an element from the set. If the element is not present, the set remains unchanged.
     *
     * @param element The element to be removed.
     */
    @Override
    public void delete(T element) {
        Finder encontrado = new Finder(element);
        if(encontrado.found){
            if(encontrado.previous == null){
                first = encontrado.current.next;
            }else{
                encontrado.previous.next = encontrado.current.next;
            }
        }
    }

    /**
     * Removes all elements from the set, making it empty.
     */
    @Override
    public void clear() {
        first = null; // de esta forma se pierde la cadena por completo ya que se pierde la referencia al primero
    }

    /**
     * Returns an iterator over elements of type {@code T}.
     *
     * @return an Iterator.
     */
    @Override
    public Iterator<T> iterator() {
        return new SortedLinkedSetIterator();
    }
}
