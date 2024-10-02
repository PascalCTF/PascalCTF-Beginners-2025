import React from "react";
import { createRoot } from "react-dom/client"
import createApp from "./App";

const appContainer = document.getElementById("react-app")
if(!appContainer) console.error("Failed to get app container")
else {
  createRoot(appContainer).render(createApp())
}
