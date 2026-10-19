import model.MyMap;
import model.Student;

import java.util.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Student s1 = new Student("Dan", 4.5f);
        Student s2 = new Student("Ana", 8.5f);
        Student s3 = new Student("Dan", 4.5f);

        System.out.println(s1.equals(s3));
        System.out.println(s1.hashCode());
        System.out.println(s3.hashCode());

        HashSet<Student> students = new HashSet<>();
        students.add(s1);
        students.add(s2);
        students.add(s3);
        System.out.println(students);

        // Ex 4 -> Tree Set
        Set<Student> treeSet = new TreeSet<>();
        treeSet.add(s1);
        treeSet.add(s2);
        treeSet.add(s3);

        for (Student student : treeSet) {
            System.out.println(student);
        }

        Comparator<Student> averageComparator = new Comparator<Student>() {
            @Override
            public int compare(Student s1, Student s2) {
                return Float.compare(s1.getAverage(), s2.getAverage());
            }
        };

        Set<Student> treeComparamble = new TreeSet<>(averageComparator);
        treeComparamble.add(s1);
        treeComparamble.add(s2);
        treeComparamble.add(s3);

        for (Student student : treeComparamble) {
            System.out.println(student);
        }

        // Ex 5 -> HashMap & TreeMap

        Map<String, Student> map = new HashMap<>();
        map.put(s1.getName(), s1);
        map.put(s2.getName(), s2);
        map.put(s3.getName(), s3);

        System.out.println(map.size());

        for (Map.Entry<String, Student> entry : map.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }

        Map<String, Student> treeMap = new TreeMap<>();
        treeMap.put(s1.getName(), s1);
        treeMap.put(s2.getName(), s2);
        treeMap.put(s3.getName(), s3);

        for (Map.Entry<String, Student> entry : treeMap.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }

        List<Student> list = new ArrayList<>();
        list.add(s1);
        list.add(s2);
        list.add(s3);
        Iterator<Student> iterator = list.iterator();
        while (iterator.hasNext()) {
            Student student = iterator.next();
            System.out.println(student);
        }

        System.out.println("-----------------");

        MyMap myMap = new MyMap();
        myMap.addStudent(new Student("Michal", 9.7f));
        myMap.addStudent(new Student("Jackson", 7.3f));
        myMap.addStudent(new Student("Calin", 6f));
        myMap.addStudent(new Student("Mihai", 6.9f));
        myMap.addStudent(new Student("Albert", 9.5f));
        myMap.addStudent(new Student("Dragos", 9.9f));

        for (Map.Entry<Integer, TreeSet<Student>> entry : myMap.getEntries()) {
            System.out.println("Key: " + entry.getKey());
            for (Student student : entry.getValue()) {
                System.out.println(student);
            }
        }
    }
}