import java.util.Calendar;

public class Student extends Person {
	private String subject;
	private Calendar immatriculationDate;
	Student(String name, String firstName, int birthyear, int birthmonth, int birthday) {
		super(name, firstName, birthyear, birthmonth, birthday);
		
	}
}
