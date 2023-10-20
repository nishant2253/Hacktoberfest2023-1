function addTask() {
    const taskInput = document.getElementById("taskInput");
    const taskList = document.getElementById("taskList");

    if (taskInput.value.trim() === "") {
        alert("Please enter a task.");
        return;
    }

    const taskText = taskInput.value;
    taskInput.value = "";

    const taskItem = document.createElement("li");
    taskItem.textContent = taskText;
    taskList.appendChild(taskItem);

    taskItem.addEventListener("click", function () {
        taskList.removeChild(taskItem);
    });
}

document.addEventListener("keydown", function (event) {
    if (event.key === "Enter") {
        addTask();
    }
});

