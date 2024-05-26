import { useState } from 'react'
/*
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
*/
import Logo from '/Logo.png'
import './App.css'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <h1 className="">
          Hello world!
      </h1>
      <img src={Logo}></img>
    </>
  )
}

export default App
