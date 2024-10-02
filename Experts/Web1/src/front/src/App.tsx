import React, { FunctionComponent, useState } from "react";


const App : FunctionComponent<Record<string, never>> = () => {
  const [description, setDescription] = useState<string>("Hello")
  return (
    <div>
      <form>
        <input type="button" value="Hi" />
      </form>
      <button onClick={() => setDescription(description => `${description}${description}`)}></button>
      <p>{description}</p>
    </div>
  )
}

const createApp = () => <App/>
export default createApp
