package model;

import java.util.Objects;

public class Student extends Entity<Integer> implements Comparable<Student> {
    private String name;
    private float average;

    public Student(String name, float average) {
        super(null);
        this.name = name;
        this.average = average;
    }

    public Student(Integer integer, String name, float average) {
        super(integer);
        this.name = name;
        this.average = average;
    }

    @Override
    public int compareTo(Student other) {
        return this.name.compareTo(other.name);
    }

    @Override
    public String toString() {
        return "Student{name='" + name + "', average=" + average + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return Float.compare(average, student.average) == 0 && Objects.equals(name, student.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, average);
    }

    public float getAverage() {
        return average;
    }

    public String getName() {
        return name;
    }
}
