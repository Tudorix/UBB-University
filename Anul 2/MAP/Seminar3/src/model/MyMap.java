package model;

import java.util.*;

public class MyMap {
    Comparator<Integer> comparator = new Comparator<Integer>() {
        @Override
        public int compare(Integer o2, Integer o1) {
            return o1.compareTo(o2);
        }
    };

    Map<Integer, TreeSet<Student>> map = new TreeMap<>(comparator);

    public void addStudent(Student student) {
        int key = Math.round(student.getAverage()); // Simple key generation based on average
        map.computeIfAbsent(key, k -> new TreeSet<>()).add(student);
    }

    public Set<Map.Entry<Integer, TreeSet<Student>>> getEntries(){
        return map.entrySet();
    }
}
