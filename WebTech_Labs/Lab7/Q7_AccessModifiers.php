<?php
class LecturerInfo {
    private $name;
    protected $department;
    public $college = "ABC College";

    public function setName($name) {
        $this->name = $name;
    }

    public function getName() {
        return $this->name;
    }

    public function setDepartment($department) {
        $this->department = $department;
    }

    public function getDepartment() {
        return $this->department;
    }
}

class HOD extends LecturerInfo {
    public function showDepartment() {
        return $this->department;
    }
}

$obj = new HOD();
$obj->setName("Dr. Khan");
$obj->setDepartment("Computer");

echo "Name: " . $obj->getName() . "<br>";
echo "Department: " . $obj->getDepartment() . "<br>";
echo "College: " . $obj->college . "<br>";
echo "Child can access protected: " . $obj->showDepartment() . "<br>";
?>
