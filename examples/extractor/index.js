const fs = require("fs");
const cp = require("child_process");
const path = require("path");

const locales = [
  "en",
  "ru",
];

const cwd = process.cwd();
const src = path.join(cwd, "examples");
const bin = path.join(cwd, "node_modules", ".bin", "bs-react-intl-extractor");

console.log(`=== ⏳  Extracting messages...`);
const extracted = JSON.parse(cp.execSync(`${bin} --allow-duplicates ${src}`));
console.log(`=== ✅  Extracting messages... done.`);

for (const locale of locales) {
  console.log(`\n=== ⏳  Updating ${locale} translation...`);
  const file = path.join(src, "translations", `${locale}.json`);

  let content;
  try {
    content = JSON.parse(fs.readFileSync(file));
  } catch(error) {
    if (error.code === "ENOENT") {
      console.log(`=== ⚠️  Translation for ${locale} wasn't found. Creating new one.`);
      content = [];
    } else {
      throw error;
    }
  }

  const cache = content.reduce(
    (acc, msg) => ({ ...acc, [msg.id]: msg }),
    {},
  );
  const messages = extracted.map(msg => ({
    id: msg.id,
    defaultMessage: msg.defaultMessage,
    message: cache[msg.id] && cache[msg.id].message ? cache[msg.id].message : "",
  }));

  fs.writeFileSync(file, JSON.stringify(messages, null, 2) + "\n");
  console.log(`=== ✅  Updating ${locale} translation... done.`);
}
