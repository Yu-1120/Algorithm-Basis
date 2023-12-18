git add .

echo "File upload successful at $(date)"

git commit -m "$(date) update"

git push -f --set-upstream origin master:master

echo File upload successful