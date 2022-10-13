public class Person {
	private String name;
	private String firstName;
	private int birthyear;
	private int birthmonth;
	private int birthday;
	
	Person(String name, String firstName, int birthyear, int birthmonth, int birthday) {
		this.name = name;
		this.firstName = firstName;
		this.birthyear = birthyear;
		this.birthmonth = birthmonth;
		this.birthday = birthday;
	}
	
	public int getBirthday() {
		return birthday;
	}
	
	public int getBirthmonth() {
		return birthmonth;
	}
	
	public int getBirthyear() {
		return birthyear;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getName() {
		return name;
	}
	
	public void setBirthday(int birthday) {
		this.birthday = birthday;
	}
	
	public void setBirthmonth(int birthmonth) {
		this.birthmonth = birthmonth;
	}
	
	public void setBirthyear(int birthyear) {
		this.birthyear = birthyear;
	}
	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	
}