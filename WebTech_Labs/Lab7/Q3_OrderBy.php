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

$seed = [
    ["Amit", 101, 78],
    ["Neha", 102, 34],
    ["Rahul", 103, 91],
    ["Pooja", 104, 62],
    ["Sanjay", 105, 45]
];

$count = $conn->query("SELECT COUNT(*) AS c FROM students")->fetch_assoc()["c"];
if ($count == 0) {
    foreach ($seed as $s) {
        $result = $s[2] >= 40 ? "Pass" : "Fail";
        $conn->query("INSERT INTO students (Student_name, RollNumber, marks_obtained, result)
            VALUES ('$s[0]', $s[1], $s[2], '$result')");
    }
}

$passed = $conn->query("SELECT COUNT(*) AS c FROM students WHERE result='Pass'")->fetch_assoc()["c"];
$failed = $conn->query("SELECT COUNT(*) AS c FROM students WHERE result='Fail'")->fetch_assoc()["c"];
?>
<!doctype html>
<html>
<head><title>Lab 7 - Order By</title></head>
<body>
<h3>Students in Ascending Order</h3>
<table border="1" cellpadding="6">
<tr><th>Name</th><th>Marks</th><th>Result</th></tr>
<?php
$res = $conn->query("SELECT * FROM students ORDER BY marks_obtained ASC");
while ($row = $res->fetch_assoc()) {
    echo "<tr><td>{$row['Student_name']}</td><td>{$row['marks_obtained']}</td><td>{$row['result']}</td></tr>";
}
?>
</table>
<p>Passed: <?php echo $passed; ?></p>
<p>Failed: <?php echo $failed; ?></p>
</body>
</html>
