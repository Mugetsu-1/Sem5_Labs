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

if (isset($_GET["delete"])) {
    $id = (int)$_GET["delete"];
    $conn->query("DELETE FROM students WHERE std_id=$id");
    header("Location: " . $_SERVER["PHP_SELF"]);
    exit;
}

if (isset($_POST["save"])) {
    $id = (int)$_POST["id"];
    $marks = (int)$_POST["marks"];
    $result = $marks >= 40 ? "Pass" : "Fail";
    $conn->query("UPDATE students SET marks_obtained=$marks, result='$result' WHERE std_id=$id");
    header("Location: " . $_SERVER["PHP_SELF"]);
    exit;
}

$edit = isset($_GET["edit"]) ? (int)$_GET["edit"] : 0;
$editRow = null;
if ($edit) {
    $editRow = $conn->query("SELECT * FROM students WHERE std_id=$edit")->fetch_assoc();
}
?>
<!doctype html>
<html>
<head><title>Lab 7 - CRUD</title></head>
<body>
<h3>Student CRUD</h3>
<?php if ($editRow) { ?>
<form method="post">
    <input type="hidden" name="id" value="<?php echo $editRow['std_id']; ?>">
    Name: <?php echo htmlspecialchars($editRow['Student_name']); ?><br><br>
    Marks: <input type="number" name="marks" value="<?php echo $editRow['marks_obtained']; ?>" required>
    <button type="submit" name="save">Update</button>
</form>
<?php } ?>
<br>
<table border="1" cellpadding="6">
    <tr><th>ID</th><th>Name</th><th>Roll</th><th>Marks</th><th>Result</th><th>Action</th></tr>
    <?php
    $res = $conn->query("SELECT * FROM students ORDER BY std_id");
    while ($row = $res->fetch_assoc()) {
        echo "<tr>
            <td>{$row['std_id']}</td>
            <td>{$row['Student_name']}</td>
            <td>{$row['RollNumber']}</td>
            <td>{$row['marks_obtained']}</td>
            <td>{$row['result']}</td>
            <td><a href='?edit={$row['std_id']}'>Edit</a> | <a href='?delete={$row['std_id']}' onclick=\"return confirm('Delete?')\">Delete</a></td>
        </tr>";
    }
    ?>
</table>
</body>
</html>
