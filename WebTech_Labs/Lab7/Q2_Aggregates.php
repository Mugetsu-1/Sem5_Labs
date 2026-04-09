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

$high = $conn->query("SELECT Student_name, marks_obtained FROM students ORDER BY marks_obtained DESC LIMIT 1")->fetch_assoc();
$low = $conn->query("SELECT Student_name, marks_obtained FROM students ORDER BY marks_obtained ASC LIMIT 1")->fetch_assoc();
$total = $conn->query("SELECT COUNT(*) AS c FROM students")->fetch_assoc()["c"];
$avg = $conn->query("SELECT AVG(marks_obtained) AS a FROM students")->fetch_assoc()["a"];
?>
<!doctype html>
<html>
<head><title>Lab 7 - Aggregates</title></head>
<body>
<h3>Student Summary</h3>
<p>Highest Marks: <?php echo $high["Student_name"] . " (" . $high["marks_obtained"] . ")"; ?></p>
<p>Lowest Marks: <?php echo $low["Student_name"] . " (" . $low["marks_obtained"] . ")"; ?></p>
<p>Total Students: <?php echo $total; ?></p>
<p>Average Marks: <?php echo round($avg, 2); ?></p>
</body>
</html>
