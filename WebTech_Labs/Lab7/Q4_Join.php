<?php
$conn = new mysqli("localhost", "root", "", "lab7");
if ($conn->connect_error) die("Connection failed");

$conn->query("CREATE TABLE IF NOT EXISTS students (
    std_id INT AUTO_INCREMENT PRIMARY KEY,
    Student_name VARCHAR(50) NOT NULL,
    RollNumber INT UNIQUE NOT NULL,
    marks_obtained INT NOT NULL,
    result VARCHAR(10) NOT NULL
)");
$conn->query("CREATE TABLE IF NOT EXISTS student_details (
    roll_number INT PRIMARY KEY,
    address VARCHAR(100),
    parents_name VARCHAR(50),
    mobile_phone VARCHAR(20),
    email VARCHAR(80)
)");

$students = [
    ["Amit", 101, 78],
    ["Neha", 102, 34],
    ["Rahul", 103, 91],
    ["Pooja", 104, 62],
    ["Sanjay", 105, 45]
];
$details = [
    [101, "Delhi", "Raj Kumar", "9991112222", "raj@example.com"],
    [102, "Pune", "Sita Devi", "9991113333", "sita@example.com"],
    [103, "Mumbai", "Anil Sharma", "9991114444", "anil@example.com"],
    [104, "Jaipur", "Meena Singh", "9991115555", "meena@example.com"],
    [105, "Bhopal", "Karan Verma", "9991116666", "karan@example.com"]
];

$count = $conn->query("SELECT COUNT(*) AS c FROM students")->fetch_assoc()["c"];
if ($count == 0) {
    foreach ($students as $s) {
        $result = $s[2] >= 40 ? "Pass" : "Fail";
        $conn->query("INSERT INTO students (Student_name, RollNumber, marks_obtained, result)
            VALUES ('$s[0]', $s[1], $s[2], '$result')");
    }
}

$dcount = $conn->query("SELECT COUNT(*) AS c FROM student_details")->fetch_assoc()["c"];
if ($dcount == 0) {
    foreach ($details as $d) {
        $conn->query("INSERT INTO student_details (roll_number, address, parents_name, mobile_phone, email)
            VALUES ($d[0], '$d[1]', '$d[2]', '$d[3]', '$d[4]')");
    }
}
?>
<!doctype html>
<html>
<head><title>Lab 7 - Join</title></head>
<body>
<h3>Failed Students Parent Details</h3>
<table border="1" cellpadding="6">
<tr><th>Name</th><th>Parent Name</th><th>Email</th></tr>
<?php
$res = $conn->query("SELECT s.Student_name, d.parents_name, d.email
    FROM students s
    JOIN student_details d ON s.RollNumber = d.roll_number
    WHERE s.result = 'Fail'");
if ($res->num_rows == 0) {
    echo "<tr><td colspan='3'>No failed students found.</td></tr>";
}
while ($row = $res->fetch_assoc()) {
    echo "<tr><td>{$row['Student_name']}</td><td>{$row['parents_name']}</td><td>{$row['email']}</td></tr>";
}
?>
</table>
</body>
</html>
