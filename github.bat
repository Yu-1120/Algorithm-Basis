git add .

echo  $(date)

git commit -m "$(date) update"

git push -f --set-upstream origin master:master

echo File upload successful