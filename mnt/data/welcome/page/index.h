<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>Welcome To My World</title>
  <link rel="stylesheet" href="styles.css">
</head>
<body>
  <div class="stars" aria-hidden="true"></div>
  <div class="shooting-stars" aria-hidden="true"></div>

  <main class="stage" role="main" aria-labelledby="headline">
    <section class="message" aria-hidden="false">
      <div class="typer" aria-live="polite">
        <div class="label">pause • reflect</div>
        <div id="headline" class="headline" aria-hidden="false"></div>
        <div class="sub">A simple line. No drama. No pressure. Just an invitation.</div>
      </div>
    </section>

    <aside class="portal-wrap" aria-hidden="true">
      <div class="portal" role="img" aria-label="A glowing portal">
        <div class="glow-ring" aria-hidden="true"></div>
        <div class="portal-inner">
          <div class="portal-core">
            <div class="portal-text">enter</div>
          </div>
        </div>
      </div>
    </aside>
  </main>

  <script src="script.js"></script>
</body>
</html>
:root{
  --bg:#05060a;
  --accent:#79ffda;
  --glow:rgba(121,255,218,0.12);
  --soft:#9bded0;
}

/* Reset and basics */
*{box-sizing:border-box;margin:0;padding:0}
html,body{height:100%}

body {
  min-height: 100vh;
  background:
    linear-gradient(180deg, rgba(5,6,10,0.85) 0%, rgba(16,28,48,0.78) 80%, rgba(121,255,218,0.11) 100%),
    url('https://images.unsplash.com/photo-1462331940025-496dfbfc7564?auto=format&fit=crop&w=1500&q=80') center center / cover no-repeat fixed;
  color:#fff;
  font-family: "Inter", "Segoe UI", Roboto, "Helvetica Neue", Arial, sans-serif;
  -webkit-font-smoothing:antialiased;
  -moz-osx-font-smoothing:grayscale;
  overflow:hidden;
  display:flex;
  align-items:center;
  justify-content:center;
  padding:2rem;
}

/* STARS - animated twinkling dots */
.stars, .stars::after {
  position: absolute;
  inset:0;
  pointer-events:none;
  z-index: 1;
}
.stars::after{
  content:"";
  transform:translateZ(0);
  background-size: 80px 80px;
  opacity:0.03;
  mix-blend-mode:screen;
}

/* Twinkling single "dot" stars (created by JS) */
.star-twinkle {
  position: absolute;
  border-radius: 50%;
  background: #fff;
  opacity: 0.7;
  width: 2px;
  height: 2px;
  animation: twinkle 3s infinite;
  z-index: 1;
}
@keyframes twinkle {
  0%,100% { opacity: 0.9; }
  48% { opacity: 0.4; }
  56% { opacity: 1; }
}

/* SHOOTING STARS COVER CONTAINER */
.shooting-stars {
  pointer-events: none;
  position: fixed;
  top: 0; left: 0; width: 100vw; height: 100vh;
  z-index: 9;
  overflow: hidden;
}

/* Single shooting star streak */
.shooting-star {
  position: absolute;
  top: 0; left: 0;
  width: 3px; height: 80px;
  background: linear-gradient(180deg, #fff 60%, rgba(255,255,255,0));
  opacity: 0.55;
  border-radius: 50%;
  transform: rotate(-45deg);
  filter: blur(0.5px);
  animation: shoot 1.6s linear forwards;
}
@keyframes shoot {
  0% {
    opacity: 0;
    transform: translateY(0) translateX(0) scaleY(1) rotate(-45deg);
  }
  7% {
    opacity: 1;
    filter: blur(0.7px);
    scale: 1.05;
  }
  80% {
    opacity: 0.7;
    filter: blur(2px);
    transform: translateY(80vh) translateX(60vw) scaleY(0.93) rotate(-45deg);
  }
  100% {
    opacity: 0;
    filter: blur(10px);
    transform: translateY(120vh) translateX(100vw) scaleY(0.89) rotate(-45deg);
  }
}

/* Center stage layout */
.stage{
  position:relative;
  width:min(920px,95%);
  max-width:980px;
  display:grid;
  grid-template-columns: 1fr 420px;
  gap:28px;
  align-items:center;
  justify-items:center;
  z-index: 3;
}

/* Message area (left) */
.message{
  width:100%;
  min-height:260px;
  display:flex;
  align-items:center;
  justify-content:center;
}
.typer{
  width:100%;
  text-align:left;
  max-width:640px;
}
.label{
  font-size:0.9rem;
  color:var(--soft);
  letter-spacing:0.12em;
  text-transform:uppercase;
  margin-bottom:10px;
  opacity:0.9;
}
.headline{
  font-size: clamp(1.6rem, 3.5vw, 2.6rem);
  line-height:1.02;
  color: #e9fff6;
  font-weight:600;
  font-family: "Courier New", Courier, monospace;
  white-space:nowrap;
  overflow:hidden;
}
.headline .cursor{
  display:inline-block;
  width:10px;
  height:1.05em;
  background:linear-gradient(180deg,var(--accent),#c1fff0);
  margin-left:8px;
  vertical-align:middle;
  animation: blink 1s steps(1) infinite;
  border-radius:2px;
  box-shadow:0 0 12px var(--glow);
}
@keyframes blink{50%{opacity:0}}

.sub{
  margin-top:14px;
  color:#bfeee2;
  opacity:0.9;
  font-size:0.95rem;
  max-width:640px;
}

/* Portal (right) */
.portal-wrap{
  width:420px;
  height:420px;
  display:flex;
  align-items:center;
  justify-content:center;
  position:relative;
}
.portal {
  width:80%;
  height:80%;
  border-radius:40% 40% 50% 50%/45% 45% 55% 55%;
  background: radial-gradient(circle at 35% 35%, rgba(121,255,218,0.12), transparent 18%),
              linear-gradient(180deg, rgba(18,18,25,0.6) 0%, rgba(7,10,14,0.9) 100%);
  border: 1px solid rgba(121,255,218,0.08);
  position:relative;
  box-shadow:
    0 20px 60px rgba(0,0,0,0.6),
    inset 0 -6px 30px rgba(0,0,0,0.6);
  display:flex;
  align-items:center;
  justify-content:center;
  transform:rotate(-6deg);
  overflow:hidden;
}
.glow-ring{
  position:absolute;
  inset:-6%;
  border-radius:50%;
  background:conic-gradient(from 120deg, rgba(121,255,218,0.06), rgba(121,255,218,0.15), rgba(0,0,0,0));
  filter:blur(12px);
  animation: ring 8s linear infinite;
  mix-blend-mode:screen;
}
@keyframes ring{to{transform:rotate(1turn)}}

.portal-inner{
  width:78%;
  height:78%;
  border-radius:50%;
  background:
    radial-gradient(circle at 50% 42%, rgba(255,255,255,0.06) 0%, rgba(121,255,218,0.05) 6%, rgba(0,0,0,0.35) 20%),
    linear-gradient(0deg, rgba(14,17,20,0.85), rgba(9,11,14,0.6));
  display:flex;
  align-items:center;
  justify-content:center;
  position:relative;
  transform:scale(0.98);
  box-shadow:0 8px 40px rgba(0,0,0,0.6) inset;
  border:1px solid rgba(255,255,255,0.02);
}
.portal-core{
  width:72%;
  height:72%;
  border-radius:50%;
  display:flex;
  align-items:center;
  justify-content:center;
  background:
    radial-gradient(circle at 35% 35%, rgba(121,255,218,0.18), rgba(10,12,14,0.5) 40%),
    radial-gradient(circle at 65% 75%, rgba(255,255,255,0.02), rgba(0,0,0,0.2) 30%);
  box-shadow: 0 6px 40px rgba(9,255,205,0.06), 0 24px 60px rgba(0,0,0,0.6);
  border:1px solid rgba(121,255,218,0.08);
  transform-origin:center;
  animation: pulse 4.5s ease-in-out infinite;
}
@keyframes pulse{
  0%{transform:scale(0.98);filter:brightness(0.98)}
  50%{transform:scale(1.03);filter:brightness(1.06)}
  100%{transform:scale(0.98);filter:brightness(0.98)}
}

.portal-core::before{
  content:"";
  position:absolute;
  width:140%;
  height:140%;
  left:-20%;
  top:-20%;
  background:radial-gradient(circle at 50% 50%, rgba(121,255,218,0.05), transparent 20%);
  filter:blur(20px);
}
.portal-text{
  color:#e8fff6;
  font-family:"Courier New", Courier, monospace;
  font-size:1rem;
  letter-spacing:0.28em;
  text-transform:uppercase;
  opacity:0.95;
}

/* Responsive */
@media (max-width:820px){
  .stage{grid-template-columns:1fr; gap:18px}
  .portal-wrap{width:96%; height:360px}
  .portal{transform:none}
}
