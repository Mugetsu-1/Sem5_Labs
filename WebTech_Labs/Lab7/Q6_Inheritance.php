<?php
class Lecturer {
    protected $name;
    protected $subject;

    public function __construct($name, $subject) {
        $this->name = $name;
        $this->subject = $subject;
    }

    public function details() {
        return $this->name . " teaches " . $this->subject;
    }
}

class Parttime extends Lecturer {
    private $hours;

    public function __construct($name, $subject, $hours) {
        parent::__construct($name, $subject);
        $this->hours = $hours;
    }

    public function details() {
        return "Parttime: " . parent::details() . ", hours = " . $this->hours;
    }
}

class Fulltime extends Lecturer {
    private $salary;

    public function __construct($name, $subject, $salary) {
        parent::__construct($name, $subject);
        $this->salary = $salary;
    }

    public function details() {
        return "Fulltime: " . parent::details() . ", salary = " . $this->salary;
    }
}

$staff = [
    new Parttime("Ravi", "PHP", 12),
    new Fulltime("Anita", "DBMS", 50000)
];

foreach ($staff as $person) {
    echo $person->details() . "<br>";
}
?>
