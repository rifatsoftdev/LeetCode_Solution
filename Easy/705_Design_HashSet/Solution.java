import java.util.*;


class MyHashSet {

    boolean arr[] = new boolean[1000001];

    MyHashSet() {
        for (int i = 0; i <= 1000000; i++) {
            arr[i] = false;
        }
    }
    
    public void add(int key) {
        arr[key] = true;
    }
    
    public void remove(int key) {
        arr[key] = false;
    }
    
    public boolean contains(int key) {
        return arr[key];
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
*/