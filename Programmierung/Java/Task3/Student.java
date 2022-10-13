import java.util.Calendar;

public class Student extends Person {
	private String subject;
	private Calendar immatriculationDate;
	Student(String name, String firstName, int birthyear, int birthmonth, int birthday, String subject, Calendar immatriculationDate) {
		super(name, firstName, birthyear, birthmonth, birthday);
		this.subject = subject;
		this.immatriculationDate = immatriculationDate;
	}
	
	public String getSubject() {
		return subject;
	}
	
	public Calendar getImmatriculationDate() {
		return immatriculationDate;
	}
	
	public void setSubject(String subject) {
		this.subject = subject;
	}
	
	public void setImmatriculationDate(Calendar immatriculationDate) {
		this.immatriculationDate = immatriculationDate;
	}
}
