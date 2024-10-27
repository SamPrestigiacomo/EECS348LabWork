<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Multiplication Table</title>
    <style>
        table {
            border-collapse: collapse;
            width: 50%;
            margin-top: 20px;
        }
        table, th, td {
            border: 1px solid black;
            padding: 5px;
            text-align: center;
        }
        th {
            background-color: #f2f2f2;
        }
    </style>
</head>
<body>
    <?php
        // Set a default number if none is provided
        $num = isset($_POST["number"]) ? intval($_POST["number"]) : 5;

        echo "<h2>Multiplication Table for $num</h2>";
        echo "<table>";

        // Header row with column indexes
        echo "<tr><th>*</th>";
        for ($i = 1; $i <= $num; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";

        // Rows with row indexes and multiplication results
        for ($i = 1; $i <= $num; $i++) {
            echo "<tr><th>$i</th>";
            for ($j = 1; $j <= $num; $j++) {
                echo "<td>" . ($i * $j) . "</td>";
            }
            echo "</tr>";
        }

        echo "</table>";
    ?>
</body>
</html>
