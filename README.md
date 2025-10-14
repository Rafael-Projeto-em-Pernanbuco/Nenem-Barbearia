
<html lang="pt-BR">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>NENEM BARBEARIA</title>
  <style>
    body {
      background-color: #000000; /* Preto escuro */
      color: #cccccc; /* Preto claro */
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 0;
    }
    header {
      background-color: #111111;
      padding: 20px;
      text-align: center;
      color: white;
      font-size: 2em;
    }
    .container {
      padding: 20px;
      text-align: center;
    }
    iframe {
      width: 100%;
      height: 300px;
      border: 0;
      margin-bottom: 20px;
    }
    .social-buttons a {
      display: inline-block;
      margin: 10px;
      text-decoration: none;
      color: #fff;
      background-color: #333;
      padding: 10px 20px;
      border-radius: 5px;
    }
    .chat-box {
      background-color: #1a1a1a;
      border: 1px solid #333;
      border-radius: 5px;
      padding: 10px;
      max-width: 400px;
      margin: 20px auto;
    }
    .chat-box textarea {
      width: 100%;
      height: 60px;
      resize: none;
      background: #000;
      color: #ccc;
      border: 1px solid #444;
      border-radius: 4px;
      margin-bottom: 10px;
    }
    .chat-box button {
      padding: 8px 16px;
      background: #444;
      color: white;
      border: none;
      cursor: pointer;
    }
  </style>
</head>
<body>

<header>NENEM BARBEARIA</header>

<div class="container">
  <h2>Nosso Endereço</h2>
  <iframe
    src="https://www.google.com/maps?q=Av.%20Canuto%20803,%20Centro,%20Exu-PE&output=embed"
    allowfullscreen>
  </iframe>

  <h2>Fale Conosco</h2>
  <div class="chat-box">
    <textarea placeholder="Digite sua mensagem..."></textarea><br>
    <button onclick="alert('Mensagem enviada! (Simulação)')">Enviar</button>
    <button onclick="startRecording()">🎤 Gravar Áudio</button>
    <p id="audio-status"></p>
  </div>

  <h2>Redes Sociais</h2>
  <div class="social-buttons">   
 <a href="https://www.youtube.com/SEUUSUARIO" target="_blank">Youtube</a>     <a href="https://wa.me/5587996838485" target="_blank">WhatsApp</a>
    <a href="https://www.instagram.com/nenem_barbearia_02?igsh=MXNtNGFidjRyOWo5MA==" target="_blank">Instagram</a>
    <a href="https://www.facebook.com/vandevanio.lourenco.2025/" target="_blank">Facebook</a>
    <a href="https://twitter.com/SEUUSUARIO" target="_blank">Twitter</a>
    <a href="https://kwai-video.com/u/@vandevaniolo/gFCvpZmK" target="_blank">Kwai</a>
    <a href="https://t.me/SEUUSUARIO" target="_blank">Telegram</a>
    <a href="https://www.tiktok.com/@wandevanio?_t=ZM-90YJELiCBCt&_r=1" target="_blank">TikTok</a>
  </div>

  <h2>Traduzir Página</h2>
  <div id="google_translate_element"></div>
</div>

<!-- Google Translate Script -->
<script type="text/javascript">
  function googleTranslateElementInit() {
    new google.translate.TranslateElement(
      { pageLanguage: 'pt', includedLanguages: 'en,es,fr,de,it,pt' },
      'google_translate_element'
    );
  }
</script>
<script src="//translate.google.com/translate_a/element.js?cb=googleTranslateElementInit"></script>

<!-- Simples Gravação de Áudio -->
<script>
  let mediaRecorder;
  let audioChunks = [];

  function startRecording() {
    if (!navigator.mediaDevices) {
      alert("Seu navegador não suporta gravação de áudio.");
      return;
    }

    navigator.mediaDevices.getUserMedia({ audio: true })
      .then(stream => {
        mediaRecorder = new MediaRecorder(stream);
        mediaRecorder.start();
        document.getElementById('audio-status').textContent = "Gravando áudio...";

        mediaRecorder.ondataavailable = event => {
          audioChunks.push(event.data);
        };

        mediaRecorder.onstop = () => {
          const audioBlob = new Blob(audioChunks, { type: 'audio/wav' });
          const audioUrl = URL.createObjectURL(audioBlob);
          const audio = new Audio(audioUrl);
          audio.play();
          document.getElementById('audio-status').textContent = "Gravação finalizada. Reproduzindo...";
        };

        setTimeout(() => {
          mediaRecorder.stop();
        }, 5000); // Grava por 5 segundos
      })
      .catch(error => {
        alert("Erro ao acessar o microfone.");
        console.error(error);
      });
  }
</script>

</body>
</html>
