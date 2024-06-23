function sendData() {
  const form = document.getElementById('login');
  const formData = new FormData(form);

  fetch('login.php', {
    method: 'POST',
    body: formData
  })
  .then(response => response.text())
  .then(data => {
    console.log(formData.user-login);
    document.getElementById('response').innerHTML = data;
  })
  .catch(error => {
    console.error('Error:', error);
  });
}
