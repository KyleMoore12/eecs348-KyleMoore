<!DOCTYPE html>
<html>
<head>
  <title>Multiplication Table</title>
</head>
<body>
  <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
      $number = $_POST["number"];
      echo "<h2>Multiplication Table for 1 to $number</h2>";
      echo "<table border='1'>";
      echo "<tr><th>&nbsp;</th>";

      // Display column headers
      for ($i = 1; $i <= $number; $i++) {
        echo "<th>$i</th>";
      }

      // Display the table
      for ($i = 1; $i <= $number; $i++) {
        echo "<tr><th>$i</th>";

        for ($j = 1; $j <= $number; $j++) {
          echo "<td>" . ($i * $j) . "</td>";
        }

        echo "</tr>";
      }

      echo "</table>";
    }
  ?>
</body>
</html>
